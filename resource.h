#define PLUG_MFR "ZachOhara"
#define PLUG_NAME "OZDSP_ToneGen"

#define PLUG_CLASS_NAME OZDSP_ToneGen

#define BUNDLE_MFR "ZachOhara"
#define BUNDLE_NAME "OZDSP_ToneGen"

#define PLUG_ENTRY OZDSP_ToneGen_Entry
#define PLUG_FACTORY OZDSP_ToneGen_Factory
#define PLUG_VIEW_ENTRY OZDSP_ToneGen_ViewEntry

#define PLUG_ENTRY_STR "OZDSP_ToneGen_Entry"
#define PLUG_VIEW_ENTRY_STR "OZDSP_ToneGen_ViewEntry"

#define VIEW_CLASS OZDSP_ToneGen_View
#define VIEW_CLASS_STR "OZDSP_ToneGen_View"

// Format        0xMAJR.MN.BG - in HEX! so version 10.1.5 would be 0x000A0105
#define PLUG_VER 0x00010000
#define VST3_VER_STR "1.0.0"

#define PLUG_COPYRIGHT  "Copyright 2019 Zach Ohara"

// http://service.steinberg.de/databases/plugin.nsf/plugIn?openForm
// 4 chars, single quotes. At least one capital letter
#define PLUG_UNIQUE_ID 'Ipef'
// make sure this is not the same as BUNDLE_MFR
#define PLUG_MFR_ID 'Acme'

// ProTools stuff

#if (defined(AAX_API) || defined(RTAS_API)) && !defined(_PIDS_)
  #define _PIDS_
  const int PLUG_TYPE_IDS[2] = {'EFN1', 'EFN2'};
  const int PLUG_TYPE_IDS_AS[2] = {'EFA1', 'EFA2'}; // AudioSuite
#endif

// TODO
#define PLUG_MFR_PT "ZachOhara\nZachOhara\nAcme"
#define PLUG_NAME_PT "OZDSP_ToneGen\nIPEF"
#define PLUG_TYPE_PT "Effect"
#define PLUG_DOES_AUDIOSUITE 1

/* PLUG_TYPE_PT can be "None", "EQ", "Dynamics", "PitchShift", "Reverb", "Delay", "Modulation", 
"Harmonic" "NoiseReduction" "Dither" "SoundField" "Effect" 
instrument determined by PLUG _IS _INST
*/

#define PLUG_CHANNEL_IO "1-1 2-2"

#define PLUG_LATENCY 0
#define PLUG_IS_INST 1

// if this is 0 RTAS can't get tempo info
#define PLUG_DOES_MIDI 0

#define PLUG_DOES_STATE_CHUNKS 0

// GUI dimensions
#define GUI_WIDTH 250
#define GUI_HEIGHT 210
// Unique IDs for each image resource
#define BACKGROUND_ID 101
#define PITCH_CONTROL_ID 201
#define VOLUME_CONTROL_ID 202
#define WAVEFORM_CONTROL_ID 203
// Image resource locations for this plug
#define BACKGROUND_FN "resources/img/ToneGen.png"
#define PITCH_CONTROL_FN "resources/img/pitch.png"
#define VOLUME_CONTROL_FN "resources/img/volume.png"
#define WAVEFORM_CONTROL_FN "resources/img/waveform.png"
// Number of frames in the bitmaps
#define PITCH_CONTROL_FRAMES 128
#define VOLUME_CONTROL_FRAMES 128
#define WAVEFORM_CONTROL_FRAMES 4

// on MSVC, you must define SA_API in the resource editor preprocessor macros as well as the c++ ones
#if defined(SA_API)
#include "app_wrapper/app_resource.h"
#endif

// vst3 stuff
#define MFR_URL "www.zachohara.com"
#define MFR_EMAIL "zjohara@gmail.com"
#define EFFECT_TYPE_VST3 "Instrument"

/* "Fx|Analyzer"", "Fx|Delay", "Fx|Distortion", "Fx|Dynamics", "Fx|EQ", "Fx|Filter",
"Fx", "Fx|Instrument", "Fx|InstrumentExternal", "Fx|Spatial", "Fx|Generator",
"Fx|Mastering", "Fx|Modulation", "Fx|PitchShift", "Fx|Restoration", "Fx|Reverb",
"Fx|Surround", "Fx|Tools", "Instrument", "Instrument|Drum", "Instrument|Sampler",
"Instrument|Synth", "Instrument|Synth|Sampler", "Instrument|External", "Spatial",
"Spatial|Fx", "OnlyRT", "OnlyOfflineProcess", "Mono", "Stereo",
"Surround"
*/
