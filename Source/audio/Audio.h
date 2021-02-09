#pragma once
#include <atomic>
#include <JuceHeader.h>
#include "../../Source/Synth/sOscillator.hpp"
#include "../../Source/Synth/SquareOscillator.hpp"
#include "../../Source/Synth/SawOscillator.hpp"
#include "../../Source/Synth/TriangleOscillator.hpp"
#include "../../Source/audio/Metronome.h"
#include "../../Source/Synth/SecondBaseOscillator.hpp"
#include "../../Source/Synth/SecondSinOscillator.hpp"
#include "../../Source/Synth/SecondSquareOscillator.hpp"
#include "../../Source/Synth/SecondTriangleOscillator.hpp"
#include "../../Source/Synth/SecondSawToothOscillator.hpp"
#include "../../Source/audio/MidiMessage.h"

/** Class containing all audio processes */

class Audio :   public MidiInputCallback,
public AudioIODeviceCallback
{
public:
    /** Constructor */
    Audio();
    
    /** Destructor */
    ~Audio();
    
    /** Returns the audio device manager, don't keep a copy of it! */
    AudioDeviceManager& getAudioDeviceManager() { return audioDeviceManager;}
    
    void handleIncomingMidiMessage (MidiInput* source, const MidiMessage& message) override;
    
    void audioDeviceIOCallback (const float** inputChannelData,
                                int numInputChannels,
                                float** outputChannelData,
                                int numOutputChannels,
                                int numSamples) override;
     
    void audioDeviceAboutToStart (AudioIODevice* device) override;
    void audioDeviceStopped() override;
    
    ///////////////////Synth/////////////////////////////////////////////

    void setOscillatorType(BaseOscillator& type, BaseOscillatorTwo& type2);
   
    void setEnvelopeParameters(std::atomic<float> *attack, std::atomic<float> *decay, std::atomic<float> *sustain, std::atomic<float> *release);
    
    void setFmParameters(std::atomic<float> *modFrequency, std::atomic<int> *modIndex);
    
    void setFilterParameters(std::atomic<float> *lpfcutOff, std::atomic<float> *lpfQ);
   ///////////////Metronome///////////////////////////////////
    
    void setMetronomeGain(std::atomic<float> newGain);
    void prepareToPlay (std::atomic<int> samplesPerBlockExpected, std::atomic<double> sampleRate);
    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill);
    void releaseResources();
    void setMetButtonState (int currentState);
    int getMetStateValue();
    void setMetronomeBPM(std::atomic<int> newBPM);
    float getMetGain();
   
    /////////////Midi///////////////////////////////////////////////
    void updateMidiMessage();
  
  
   
    MyMidiMessage m_Midi;
private:
    
    float sampleRate = {0.f};
    int bufferSize = 0;
    
    //////////////////Synth objects and global variables/////////////////
    AudioDeviceManager audioDeviceManager;
    BaseOscillator* oscillator;
    BaseOscillatorTwo* oscillator2;
    BaseOscillator* lfo;
    SinOscillator sin;
    SinOscillatorTwo sin2;
    std::atomic<float> currentFrequency = {0.f};
    
    ADSR adsr;
    ADSR::Parameters adsrParams; /** Allows accsess to envelope paramaters within ADSR class */
    float fmodFrequency = {0.f};
    int fmodIndex = 0.f;
    float fmSum = {0.f};

    IIRFilter Nyquist;
    IIRFilter Nyquist2;
    
    IIRFilter lpf;
    IIRFilter lpf2;
    
    IIRFilter lpfImproving;
    IIRFilter lpf2Improving;
    
   
    
    
   ///////////////////Metronome Objects and global variables //////////////////
    Metronome met;
    AudioSourcePlayer metaudiosourceplayer;
    MixerAudioSource combinedOutput;
    int metglobVal = 0;
};

