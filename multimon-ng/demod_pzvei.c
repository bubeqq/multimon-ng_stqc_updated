/*
 *      demod_pzvei.c
 *
 *      Copyright (C) 2013
 *          Elias Oenal    (EliasOenal@gmail.com)
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#define SAMPLE_RATE 22050
#define PHINC(x) ((x)*0x10000/SAMPLE_RATE)

#include "multimon.h"

static const unsigned int pzvei_freq[16] = {
    PHINC(2400), PHINC(1060), PHINC(1160), PHINC(1270),
    PHINC(1400), PHINC(1530), PHINC(1670), PHINC(1830),
    PHINC(2000), PHINC(2200), PHINC(970), PHINC(810),
    PHINC(2800), PHINC(885), PHINC(2400), PHINC(680)
};

/* ---------------------------------------------------------------------- */

static void pzvei_init(struct demod_state *s)
{
    selcall_init(s);
}

static void pzvei_deinit(struct demod_state *s)
{
    selcall_deinit(s);
}

static void pzvei_demod(struct demod_state *s, buffer_t buffer, int length)
{
    selcall_demod(s, buffer.fbuffer, length, pzvei_freq, demod_pzvei.name);
}

const struct demod_param demod_pzvei = {
    "PZVEI", true, SAMPLE_RATE, 0, pzvei_init, pzvei_demod, pzvei_deinit
};



