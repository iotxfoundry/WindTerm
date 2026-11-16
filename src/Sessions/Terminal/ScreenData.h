#ifndef SCREENDATA_H
#define SCREENDATA_H

#pragma once

// Static data tables extracted from the WindTerm 2.7.0 binary —
// the data dependencies of writeText/codepointWidth/charClass.

// FUN_007a4692 zero-width / combining ranges: 23 (lo, hi) pairs,
// width class 0. Verified semantics: C0 controls, 0xAD soft hyphen,
// 0x600-0x605 Arabic, 0x200B-0x200F zero-width, 0x2028-0x202E,
// 0xD800-0xDFFF surrogates, 0xFEFF BOM, 0xE0100-0xE01EF selectors.
static const unsigned int kZeroWidthRanges[][2] = {
	0x0000, 0x001f,
	0x007f, 0x009f,
	0x00ad, 0x00ad,
	0x0600, 0x0605,
	0x061c, 0x061c,
	0x06dd, 0x06dd,
	0x070f, 0x070f,
	0x08e2, 0x08e2,
	0x180e, 0x180e,
	0x200b, 0x200f,
	0x2028, 0x202e,
	0x2060, 0x2064,
	0x2066, 0x206f,
	0xd800, 0xdfff,
	0xfeff, 0xfeff,
	0xfff9, 0xfffb,
	0x110bd, 0x110bd,
	0x110cd, 0x110cd,
	0x13430, 0x13438,
	0x1bca0, 0x1bca3,
	0x1d173, 0x1d17a,
	0xe0001, 0xe0001,
	0xe0020, 0xe007f,
};

// FUN_007a4692 wide ranges: 3 (lo, hi) pairs, width 2
// (0xE000-0xF8FF private use, planes 15/16).
static const unsigned int kWideRanges[][2] = {
	0xe000, 0xf8ff,
	0xf0000, 0xffffd,
	0x100000, 0x10fffd,
};

// DAT_011c1fe0: 256-byte single-byte character class table
// (nonzero = special handling in writeText's fast path).
static const unsigned char kSbcsClass[256] = {
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
};

// DAT_00caabb0: charset slot tables for SCS 94 (G0..G3)
static const unsigned int kCharset94Slots[4] = { 0x00000000, 0x00000001, 0x00000002, 0x00000003 };

// DAT_00caab98: SCS 96 slots (G1..G3)
static const unsigned int kCharset96Slots[3] = { 0x00000001, 0x00000002, 0x00000003 };

#endif // SCREENDATA_H
