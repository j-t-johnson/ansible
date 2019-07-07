#pragma once

#include "main.h"

#define ARC_NUM_PRESETS 8

typedef struct {
	uint16_t pattern[4][16];
	uint8_t note[4][16];
	bool mode[4];
	bool all[4];
	uint8_t now;
	uint8_t start;
	int8_t len;
	uint8_t dir;
	uint8_t scale[4];
	uint8_t octave[4];
	uint16_t offset[4];
	uint16_t range[4];
	uint16_t slew[4];
} levels_data_t;

extern levels_data_t l;

typedef struct {
	// uint32_t clock_period;
	uint8_t preset;
	levels_data_t l[ARC_NUM_PRESETS];
} levels_state_t;

typedef struct {
	uint16_t pos[4];
	int16_t speed[4];
	int8_t mult[4];
	uint8_t range[4];
	uint8_t mode;
	uint8_t shape;
	uint8_t friction;
	uint16_t force;
	uint8_t div[4];
} cycles_data_t;

extern cycles_data_t c;

typedef struct {
	// uint32_t clock_period;
	uint8_t preset;
	cycles_data_t c[ARC_NUM_PRESETS];
} cycles_state_t;

typedef struct {
	uint16_t now[4];
	uint16_t step[4];
	uint8_t loop[4];
	uint8_t lcnt[4];
	bool trmode[4];
	bool active[4];
	bool retrig[4];
	uint8_t range[4];
	uint16_t vmin;
	uint16_t vmax;
	uint16_t tmin;
	uint16_t tmax;
	bool fall[4];
	bool chain[4];
} contours_data_t;

extern contours_data_t r;

typedef struct {
	// uint32_t clock_period;
	uint8_t preset;
	contours_data_t r[ARC_NUM_PRESETS];
} contours_state_t;

void set_mode_arc(void);
void handler_ArcFrontShort(s32 data);
void handler_ArcFrontLong(s32 data);
void arc_keytimer(void);
void refresh_arc_preset(void);
void handler_ArcPresetEnc(s32 data);
void handler_ArcPresetKey(s32 data);
void ii_arc(uint8_t* data, uint8_t len);

void default_levels(void);
void init_levels(void);
void resume_levels(void);
void clock_levels(uint8_t phase);
void ii_levels(uint8_t *d, uint8_t l);
void refresh_levels(void);
void refresh_levels_change(void);
void refresh_levels_config(void);
void handler_LevelsEnc(s32 data);
void handler_LevelsRefresh(s32 data);
void handler_LevelsKey(s32 data);
void handler_LevelsTr(s32 data);
void handler_LevelsTrNormal(s32 data);

void default_cycles(void);
void init_cycles(void);
void resume_cycles(void);
void clock_cycles(uint8_t phase);
void ii_cycles(uint8_t *d, uint8_t l);
void refresh_cycles(void);
void refresh_cycles_config(void);
void refresh_cycles_config_range(void);
void refresh_cycles_config_div(void);
void handler_CyclesEnc(s32 data);
void handler_CyclesRefresh(s32 data);
void handler_CyclesKey(s32 data);
void handler_CyclesTr(s32 data);
void handler_CyclesTrNormal(s32 data);

void default_contours(void);
void init_contours(void);
void resume_contours(void);
void clock_contours(uint8_t phase);
void ii_contours(uint8_t *d, uint8_t l);
void refresh_contours(void);
void refresh_contours_change(void);
void refresh_contours_config(void);
void handler_ContoursEnc(s32 data);
void handler_ContoursRefresh(s32 data);
void handler_ContoursKey(s32 data);
void handler_ContoursTr(s32 data);
void handler_ContoursTrNormal(s32 data);
