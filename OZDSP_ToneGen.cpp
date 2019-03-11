#include "OZDSP_ToneGen.h"
#include "IPlug_include_in_plug_src.h"
#include "resource.h"

const int kNumPrograms = 0;

enum EParams
{
	kPitchPid,
	kWaveformPid,
	kVolumePid,
	kNumParams
};

std::vector<ParameterInfo> kParameterList = 
{
	ParameterInfo()
		.InitParam("Pitch", kPitchPid, KNOB_120_ID, 15, 50)
		.InitLabel()
		.MakeFrequencyParam(),
	ParameterInfo()
		.InitParam("Waveform", kWaveformPid, WAVESELECT_ID, 155, 10)
		.MakeWaveformParam(),
	ParameterInfo()
		.InitParam("Volume", kVolumePid, KNOB_80_ID, 155, 90)
		.InitLabel()
		.MakeVolumeReductionParam(),
};

OZDSP_ToneGen::OZDSP_ToneGen(IPlugInstanceInfo instanceInfo) :
	CommonPlugBase(instanceInfo, kNumParams, kNumPrograms,
		MakeGraphics(this, GUI_WIDTH, GUI_HEIGHT),
		COMMONPLUG_CTOR_PARAMS),
	mOscillator(this),
	mVolumeProcessor(this)
{
	SetBackground(BACKGROUND_ID, BACKGROUND_FN);

	RegisterBitmap(KNOB_80_ID, KNOB_80_FN, KNOB_FRAMES);
	RegisterBitmap(KNOB_120_ID, KNOB_120_FN, KNOB_FRAMES);
	RegisterBitmap(WAVESELECT_ID, WAVESELECT_FN, WAVESELECT_FRAMES);

	AddParameters(kParameterList);

	RegisterProcessor(&mOscillator);
	RegisterProcessorParameter(&mOscillator, kPitchPid, kOscillatorFrequencyParam);
	RegisterProcessorParameter(&mOscillator, kWaveformPid, kOscillatorModeParam);

	RegisterProcessor(&mVolumeProcessor);
	RegisterProcessorParameter(&mVolumeProcessor, kVolumePid, kVolumeProcessorDecibelsParam);

	FinishConstruction();
}

OZDSP_ToneGen::~OZDSP_ToneGen()
{
}

void OZDSP_ToneGen::CreatePresets()
{
	// No presets
}

void OZDSP_ToneGen::ProcessDoubleReplacing(double** inputs, double** outputs, int nFrames)
{
	// Mutex is already locked for us.
	const int nChannels = 2;

	for (int i = 0; i < nFrames; i++)
	{
		double sampleValue = mOscillator.GetNextSample();
		sampleValue = mVolumeProcessor.GetAdjustedSample(sampleValue);
		for (int j = 0; j < nChannels; j++)
		{
			outputs[j][i] = sampleValue;
		}
	}
}
