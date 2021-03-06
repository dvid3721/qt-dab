#
/*
 *    Copyright (C) 2014 .. 2017
 *    Jan van Katwijk (J.vanKatwijk@gmail.com)
 *    Lazy Chair Programming
 *
 *    This file is part of the Qt-DB program
 *    Qt-DAB is free software; you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation; either version 2 of the License, or
 *    (at your option) any later version.
 *
 *    Qt-DAB is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with Qt-DAB; if not, write to the Free Software
 *    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef	__TII_PROCESSOR__
#define	__TII_PROCESSOR__

#include	<stdint.h>
#include	"dab-params.h"
#include	"fft.h"

class	TII_Detector {
public:
		TII_Detector	(uint8_t dabMode);
		~TII_Detector	(void);
	bool	processNULL	(DSPCOMPLEX *, DSPCOMPLEX *, int16_t *, int16_t *);
	int16_t	find_C		(DSPCOMPLEX *, DSPCOMPLEX *, int16_t);
private:
	dabParams	params;
	int16_t		T_u;
	int16_t		carriers;
	bool		ind;
	DSPCOMPLEX	*theBuffer;
	DSPCOMPLEX	*buffer_2;
	common_fft	*fft_handler;
	DSPCOMPLEX	*fft_buffer;
	int16_t		fillCount;
	int16_t		A		(uint8_t c, uint8_t p, int16_t k);
	float		correlate	(DSPCOMPLEX *,
	                                 int16_t, uint64_t,
	                                 DSPCOMPLEX *, float);
	float		correlate_2	(DSPCOMPLEX *,
	                                 int16_t, int16_t, DSPCOMPLEX *);

	struct nullTable {
	   int16_t	carrier;
	   uint64_t	pattern;
	} theTable [70];
};

#endif

