

#pragma once

#include "quantum.h"



#define LAYOUT_split_4x6( \
	L00,	L01,	L02,	L03,	L04,	L05,				R05,	R04,	R03,	R02,	R01,	R00,\
	L10,	L11,	L12,	L13,	L14,	L15,				R15,	R14,	R13,	R12,	R11,	R10,\
	L20,	L21,	L22,	L23,	L24,	L25,				R25,	R24,	R23,	R22,	R21,	R20, \
	L30,	L31,	L32,	L33,	L34,	L35,				R35,	R34,	R33,	R32,	R31,	R30, \
							L40,	L41,	L42,				R42,	R41, 	R40\
) {\
	{	L00,	L01,	L02,	L03,	L04,	L05},\
	{	L10,	L11,	L12,	L13,	L14,	L15},\
	{	L20,	L21,	L22,	L23,	L24,	L25},\
	{	L30,	L31,	L32,	L33,	L34,	L35},\
	{	L40,	L41,	L42,	KC_NO,KC_NO,KC_NO},\
	{	R00,	R01,	R02,	R03,	R04,	R05},\
	{	R10,	R11,	R12,	R13,	R14,	R15},\
	{	R20,	R21,	R22,	R23,	R24,	R25},\
	{	R30,	R31,	R32,	R33,	R34,	R35},\
	{	R40,	R41,	R42,	KC_NO,KC_NO,KC_NO}\
}

#define LAYOUT_split_4x6_encoder( \
	L00,	L01,	L02,	L03,	L04,	L05,								R05,	R04,	R03,	R02,	R01,	R00,\
	L10,	L11,	L12,	L13,	L14,	L15,								R15,	R14,	R13,	R12,	R11,	R10,\
	L20,	L21,	L22,	L23,	L24,	L25,								R25,	R24,	R23,	R22,	R21,	R20, \
	L30,	L31,	L32,	L33,	L34,	L35,	L36,		R36,	R35,	R34,	R33,	R32,	R31,	R30, \
							L40,	L41,	L42,								R42,	R41, 	R40\
) {\
	{	L00,	L01,	L02,	L03,	L04,	L05},\
	{	L10,	L11,	L12,	L13,	L14,	L15},\
	{	L20,	L21,	L22,	L23,	L24,	L25},\
	{	L30,	L31,	L32,	L33,	L34,	L35},\
	{	L36,	L40,	L41,	L42,	KC_NO,KC_NO},\
	{	R00,	R01,	R02,	R03,	R04,	R05},\
	{	R10,	R11,	R12,	R13,	R14,	R15},\
	{	R20,	R21,	R22,	R23,	R24,	R25},\
	{	R30,	R31,	R32,	R33,	R34,	R35},\
	{	R36,	R42,	R41,	R40,	KC_NO,KC_NO}\
}

