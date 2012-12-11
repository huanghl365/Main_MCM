/* linux/drivers/media/video/ov9650.h
 *
 * Copyright (c) 2010 Samsung Electronics Co., Ltd.
 *	         http://www.samsung.com/
 *
 * Driver for ov9650 (UXGA camera) from Samsung Electronics
 * 1/4" 2.0Mp CMOS Image Sensor SoC with an Embedded Image Processor
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __OV9650_H__
#define __OV9650_H__

struct ov9650_reg {
	unsigned char addr;
	unsigned char val;
};

struct ov9650_regset_type {
	unsigned char *regset;
	int len;
};

/*
 * Macro
 */
#define REGSET_LENGTH(x)	(sizeof(x)/sizeof(ov9650_reg))

/*
 * User defined commands
 */
/* S/W defined features for tune */
#define REG_DELAY	0xFF00	/* in ms */
#define REG_CMD		0xFFFF	/* Followed by command */

/* Following order should not be changed */
enum image_size_ov9650 {
	/* This SoC supports upto UXGA (1600*1200) */
	QQVGA,	/* 160*120 */
	QCIF,	/* 176*144 */
	QVGA,	/* 320*240 */
	CIF,	/* 352*288 */
	VGA,	/* 640*480 */
	SVGA,	/* 800*600 */
	HD720P,	/* 1280*720 */
	SXGA,	/* 1280*1024 */
	UXGA,	/* 1600*1200 */
};

/*
 * Following values describe controls of camera
 * in user aspect and must be match with index of ov9650_regset[]
 * These values indicates each controls and should be used
 * to control each control
 */
enum ov9650_control {
	ov9650_INIT,
	ov9650_EV,
	ov9650_AWB,
	ov9650_MWB,
	ov9650_EFFECT,
	ov9650_CONTRAST,
	ov9650_SATURATION,
	ov9650_SHARPNESS,
};

#define ov9650_REGSET(x)	{	\
	.regset = x,			\
	.len = sizeof(x)/sizeof(ov9650_reg),}


/*
 * User tuned register setting values
 */
////vga 15fps 24M 640*680 YUV
unsigned char ov9650_init_reg[][2] = {
#if 0
{0x12,0x80},
{0x11,0x81},
{0x6b,0x0a},
{0x6a,0x3e},
{0x3b,0x09},
{0x13,0xe0},
{0x01,0x80},
{0x02,0x80},
{0x00,0x00},
{0x10,0x00},
{0x13,0xe5},

{0x39,0x43},//;50 for 30fps 
{0x38,0x12},//;92 for 30fps 
{0x37,0x00},
{0x35,0x91},// ;81 for 30fps 
{0x0e,0x20},
{0x1e,0x04},

{0xA8,0x80},
{0x12,0x40},
{0x04,0x00},
{0x0c,0x04},
{0x0d,0x80},
{0x18,0xc6},
{0x17,0x26},
{0x32,0xad},
{0x03,0x00},
{0x1a,0x3d},
{0x19,0x01},
{0x3f,0xa6},
{0x14,0x2e},
{0x15,0x02},
{0x41,0x02},
{0x42,0x08},

{0x1b,0x00},
{0x16,0x06},
{0x33,0xe2},//;c0 for internal regulator 
{0x34,0xbf},
{0x96,0x04},
{0x3a,0x00},
{0x8e,0x00},

{0x3c,0x77},
{0x8B,0x06},
{0x94,0x88},
{0x95,0x88},
{0x40,0xc1},
{0x29,0x3f},//;2f for},internal},regulator 
{0x0f,0x42},

{0x3d,0x92},
{0x69,0x40},
{0x5C,0xb9},
{0x5D,0x96},
{0x5E,0x10},
{0x59,0xc0},
{0x5A,0xaf},
{0x5B,0x55},
{0x43,0xf0},
{0x44,0x10},
{0x45,0x68},
{0x46,0x96},
{0x47,0x60},
{0x48,0x80},
{0x5F,0xe0},
{0x60,0x8c},//0c for advanced AWB (related to lens)
{0x61,0x20},
{0xa5,0xd9},
{0xa4,0x74},
{0x8d,0x02},
{0x13,0xe7},

{0x4f,0x3a},
{0x50,0x3d},
{0x51,0x03},
{0x52,0x12},
{0x53,0x26},
{0x54,0x38},
{0x55,0x40},
{0x56,0x40},
{0x57,0x40},
{0x58,0x0d},

{0x8C,0x23},
{0x3E,0x02},
{0xa9,0xb8},
{0xaa,0x92},
{0xab,0x0a},
#if 0
{0x8f,0xdf},
{0x90,0x00},
{0x91,0x00},
{0x9f,0x00},
{0xa0,0x00},
{0x3A,0x01},
#elif 1
{0x8f,0xdf},
{0x90,0x14},
{0x91,0x18},
{0x9f,0x0d},
{0xa0,0x0d},
{0x3A,0x01},
#elif 0
{0x90, 0x00}, {0x91, 0x00}, {0x9f, 0x00}, {0x3a, 0x0c},
#elif 0
{0x8f,0xdf},
{0x90,0x00},
{0x91,0x00},
{0x9f,0x00},
{0xa0,0x00},
{0x3A,0x0D},  
#endif
{0x24,0x70},
{0x25,0x64},
{0x26,0xc3},

{0x2a,0x00},//10 for 50Hz},
{0x2b,0x00},//40 for 50Hz},

//gamma
{0x6c,0x40},
{0x6d,0x30},
{0x6e,0x4b},
{0x6f,0x60},
{0x70,0x70},
{0x71,0x70},
{0x72,0x70},
{0x73,0x70},
{0x74,0x60},
{0x75,0x60},
{0x76,0x50},
{0x77,0x48},
{0x78,0x3a},
{0x79,0x2e},
{0x7a,0x28},
{0x7b,0x22},
{0x7c,0x04},
{0x7d,0x07},
{0x7e,0x10},
{0x7f,0x28},
{0x80,0x36},
{0x81,0x44},
{0x82,0x52},
{0x83,0x60},
{0x84,0x6c},
{0x85,0x78},
{0x86,0x8c},
{0x87,0x9e},
{0x88,0xbb},
{0x89,0xd2},
{0x8a,0xe6},
//-------------------------SXGA 1280*1028 15fps-------------------
#elif 1
        /* OV9650 intialization parameter table for SXGA application */        
    {0x12, 0x80}, {0x39, 0x43}, {0x38, 0x12}, {0x37, 0x00}, {0x0e, 0x20},
    {0x01, 0x80}, {0x02, 0x80}, {0x00, 0x00}, {0x10, 0xf0},
    {0x04, 0x00}, {0x0c, 0x00}, {0x0d, 0x00}, {0x11, 0x80}, {0x12, 0x00},
    {0x14, 0x2e}, {0x15, 0x00}, {0x18, 0xbd}, {0x17, 0x1d}, {0x32, 0xbf}, 
    {0x03, 0x12}, {0x1a, 0x81}, {0x19, 0x01}, {0x3f, 0xa6}, {0x41, 0x02},
    {0x42, 0x08}, {0x1b, 0x00}, {0x16, 0x06}, {0x33, 0xc0}, {0x34, 0xbf},
    {0xa8, 0x80}, {0x96, 0x04}, {0x3a, 0x00}, {0x8e, 0x00}, {0x3c, 0x77}, 
    {0x8b, 0x06}, {0x35, 0x91}, {0x94, 0x88}, {0x95, 0x88}, {0x40, 0xc1}, 
    {0x29, 0x3f}, {0x0f, 0x42}, {0x13, 0xe5}, {0x3d, 0x92}, {0x69, 0x80}, 
    {0x5c, 0x96}, {0x5d, 0x96}, {0x5e, 0x10}, {0x59, 0xeb}, {0x5a, 0x9c},
    {0x5b, 0x55}, {0x43, 0xf0}, {0x44, 0x10}, {0x45, 0x55}, {0x46, 0x86},
    {0x47, 0x64}, {0x48, 0x86}, {0x5f, 0xe0}, {0x60, 0x8c}, {0x61, 0x20},
    {0xa5, 0xd9}, {0xa4, 0x74}, {0x8d, 0x02}, {0x13, 0xe7}, {0x4f, 0x3a}, 
    {0x50, 0x3d}, {0x51, 0x03}, {0x52, 0x12}, {0x53, 0x26}, {0x54, 0x38},
    {0x55, 0x40}, {0x56, 0x40}, {0x57, 0x40}, {0x58, 0x0d}, {0x8c, 0x23},
    {0x3e, 0x02}, {0xa9, 0xb8}, {0xaa, 0x92}, {0xab, 0x0a}, {0x8f, 0xdf},
    {0x90, 0x00}, {0x91, 0x00}, {0x9f, 0x00}, {0x3a, 0x0c}, {0x24, 0x70},
    {0x25, 0x64}, {0x26, 0xc3}, {0x2a, 0x12}, {0x2b, 0x46}, {0x3b, 0x19},
    {0x6c, 0x40}, {0x6d, 0x30}, {0x6e, 0x4b}, {0x6f, 0x60},  
    {0x70, 0x70}, {0x71, 0x70}, {0x72, 0x70}, {0x73, 0x70},
    {0x74, 0x60}, {0x75, 0x60}, {0x76, 0x50}, {0x77, 0x48},
    {0x78, 0x3a}, {0x79, 0x2e}, {0x7a, 0x28}, {0x7b, 0x22},
    {0x7c, 0x04}, {0x7d, 0x07}, {0x7e, 0x10}, {0x7f, 0x28},
    {0x80, 0x36}, {0x81, 0x44}, {0x82, 0x52}, {0x83, 0x60},
    {0x84, 0x6c}, {0x85, 0x78}, {0x86, 0x8c}, {0x87, 0x9e},
    {0x88, 0xbb}, {0x89, 0xd2}, {0x8a, 0xe6},
    {0x6a, 0x41}, {0x66, 0x00},
    {0x3e, 0x00}, {0x3f, 0xa4},
	    {0x1e, 0x30},
#endif
};


#define ov9650_INIT_REGS	((sizeof(ov9650_init_reg)/sizeof(ov9650_init_reg[0])))

/*
 * EV bias
 */

static const struct ov9650_reg ov9650_ev_m6[] = {
};

static const struct ov9650_reg ov9650_ev_m5[] = {
};

static const struct ov9650_reg ov9650_ev_m4[] = {
};

static const struct ov9650_reg ov9650_ev_m3[] = {
};

static const struct ov9650_reg ov9650_ev_m2[] = {
};

static const struct ov9650_reg ov9650_ev_m1[] = {
};

static const struct ov9650_reg ov9650_ev_default[] = {
};

static const struct ov9650_reg ov9650_ev_p1[] = {
};

static const struct ov9650_reg ov9650_ev_p2[] = {
};

static const struct ov9650_reg ov9650_ev_p3[] = {
};

static const struct ov9650_reg ov9650_ev_p4[] = {
};

static const struct ov9650_reg ov9650_ev_p5[] = {
};

static const struct ov9650_reg ov9650_ev_p6[] = {
};

/* Order of this array should be following the querymenu data */
static const unsigned char *ov9650_regs_ev_bias[] = {
	(unsigned char *)ov9650_ev_m6, (unsigned char *)ov9650_ev_m5,
	(unsigned char *)ov9650_ev_m4, (unsigned char *)ov9650_ev_m3,
	(unsigned char *)ov9650_ev_m2, (unsigned char *)ov9650_ev_m1,
	(unsigned char *)ov9650_ev_default, (unsigned char *)ov9650_ev_p1,
	(unsigned char *)ov9650_ev_p2, (unsigned char *)ov9650_ev_p3,
	(unsigned char *)ov9650_ev_p4, (unsigned char *)ov9650_ev_p5,
	(unsigned char *)ov9650_ev_p6,
};

/*
 * Auto White Balance configure
 */
static const struct ov9650_reg ov9650_awb_off[] = {
};

static const struct ov9650_reg ov9650_awb_on[] = {
};

static const unsigned char *ov9650_regs_awb_enable[] = {
	(unsigned char *)ov9650_awb_off,
	(unsigned char *)ov9650_awb_on,
};

/*
 * Manual White Balance (presets)
 */
static const struct ov9650_reg ov9650_wb_tungsten[] = {

};

static const struct ov9650_reg ov9650_wb_fluorescent[] = {

};

static const struct ov9650_reg ov9650_wb_sunny[] = {

};

static const struct ov9650_reg ov9650_wb_cloudy[] = {

};

/* Order of this array should be following the querymenu data */
static const unsigned char *ov9650_regs_wb_preset[] = {
	(unsigned char *)ov9650_wb_sunny,
	(unsigned char *)ov9650_wb_cloudy,
	(unsigned char *)ov9650_wb_tungsten,
	(unsigned char *)ov9650_wb_fluorescent,
};

/*
 * Color Effect (COLORFX)
 */
static const struct ov9650_reg ov9650_color_normal[] = {
};

static const struct ov9650_reg ov9650_color_monochrome[] = {
};

static const struct ov9650_reg ov9650_color_sepia[] = {
};

static const struct ov9650_reg ov9650_color_aqua[] = {
};

static const struct ov9650_reg ov9650_color_negative[] = {
};

static const struct ov9650_reg ov9650_color_sketch[] = {
};

/* Order of this array should be following the querymenu data */
static const unsigned char *ov9650_regs_color_effect[] = {
	(unsigned char *)ov9650_color_normal,
	(unsigned char *)ov9650_color_monochrome,
	(unsigned char *)ov9650_color_sepia,
	(unsigned char *)ov9650_color_aqua,
	(unsigned char *)ov9650_color_sketch,
	(unsigned char *)ov9650_color_negative,
};

/*
 * Contrast bias
 */
static const struct ov9650_reg ov9650_contrast_m2[] = {
};

static const struct ov9650_reg ov9650_contrast_m1[] = {
};

static const struct ov9650_reg ov9650_contrast_default[] = {
};

static const struct ov9650_reg ov9650_contrast_p1[] = {
};

static const struct ov9650_reg ov9650_contrast_p2[] = {
};

static const unsigned char *ov9650_regs_contrast_bias[] = {
	(unsigned char *)ov9650_contrast_m2,
	(unsigned char *)ov9650_contrast_m1,
	(unsigned char *)ov9650_contrast_default,
	(unsigned char *)ov9650_contrast_p1,
	(unsigned char *)ov9650_contrast_p2,
};

/*
 * Saturation bias
 */
static const struct ov9650_reg ov9650_saturation_m2[] = {
};

static const struct ov9650_reg ov9650_saturation_m1[] = {
};

static const struct ov9650_reg ov9650_saturation_default[] = {
};

static const struct ov9650_reg ov9650_saturation_p1[] = {
};

static const struct ov9650_reg ov9650_saturation_p2[] = {
};

static const unsigned char *ov9650_regs_saturation_bias[] = {
	(unsigned char *)ov9650_saturation_m2,
	(unsigned char *)ov9650_saturation_m1,
	(unsigned char *)ov9650_saturation_default,
	(unsigned char *)ov9650_saturation_p1,
	(unsigned char *)ov9650_saturation_p2,
};

/*
 * Sharpness bias
 */
static const struct ov9650_reg ov9650_sharpness_m2[] = {
};

static const struct ov9650_reg ov9650_sharpness_m1[] = {
};

static const struct ov9650_reg ov9650_sharpness_default[] = {
};

static const struct ov9650_reg ov9650_sharpness_p1[] = {
};

static const struct ov9650_reg ov9650_sharpness_p2[] = {
};

static const unsigned char *ov9650_regs_sharpness_bias[] = {
	(unsigned char *)ov9650_sharpness_m2,
	(unsigned char *)ov9650_sharpness_m1,
	(unsigned char *)ov9650_sharpness_default,
	(unsigned char *)ov9650_sharpness_p1,
	(unsigned char *)ov9650_sharpness_p2,
};

#endif
