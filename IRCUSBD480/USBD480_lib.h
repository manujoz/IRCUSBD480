#pragma once

#include <cstdint>

#define 	USBD480_API						_declspec(dllimport);
#define 	USBD480_OK						1;
#define 	USBD480_ERROR					0;
#define 	USBD480_OPEN_WITH_USERNAME		0x01;

typedef struct {
	char Name;
	char SerialNumber;
	uint32_t Width;
	uint32_t Height;
	uint32_t PixelFormat;
	uint32_t Handle;
	uint32_t Version;
}DisplayInfo;

typedef struct {
	uint16_t y;
	uint16_t x;
	uint16_t z1;
	uint16_t z2;
	uint8_t pen;
	uint8_t pressure;
	uint8_t reserved;
}TouchReport;


enum PIXEL_FORMAT {
	PF_1BPP = 0, PF_1BPP_DS, PF_2BPP, PF_4BPP,
	PF_8BPP, PF_16BPP_RGB565, PF_16BPP_BGR565, PF_32BPP
};

extern "C" int USBD480_GetNumberOfDisplays(void);
extern "C" int USBD480_GetDisplayConfiguration(uint32_t index, DisplayInfo * di);
extern "C" int USBD480_Open(DisplayInfo * di, uint32_t flags);
extern "C" int USBD480_Close(DisplayInfo * di);
extern "C" int USBD480_DrawFullScreen(DisplayInfo * di, uint8_t * fb);
extern "C" int USBD480_DrawFullScreenRGBA32(DisplayInfo * di, uint32_t * fb);
extern "C" int USBD480_DrawFullScreenBGRA32(DisplayInfo * di, uint32_t * fb);
extern "C" int USBD480_SetBrightness(DisplayInfo * di, uint32_t brightness);
extern "C" int USBD480_SetTouchMode(DisplayInfo * di, uint32_t mode);
extern "C" int USBD480_SetAddress(DisplayInfo * di, uint32_t address);
extern "C" int USBD480_SetFrameStartAddress(DisplayInfo * di, uint32_t address);
extern "C" int USBD480_DrawFromBuffer(DisplayInfo * di, uint8_t * fb, uint32_t size);
extern "C" int USBD480_GetTouchReport(DisplayInfo * di, TouchReport * touch);
extern "C" int USBD480_GetTouchPosition(DisplayInfo * di, uint32_t * x, uint32_t * y);
extern "C" int USBD480_SetStartupImage(DisplayInfo * di, uint8_t * buffer, uint32_t size);
extern "C" int USBD480_UpdateFPGA(DisplayInfo * di);
extern "C" int USBD480_UpdateFW(DisplayInfo * di);

