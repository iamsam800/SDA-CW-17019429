//
//  Metronome.h
//  JuceAudio - App
//
//  Created by Sam Scott on 03/01/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#pragma once

#include <JuceHeader.h>
//#include "/Users/samscott/Desktop/JuceSDA/Practical 6/JuceAudio/Source/audio/Audio.h"

class Metronome : public HighResolutionTimer, public AudioTransportSource


{
public:
    Metronome();
    
    void prepareToPlay (int samplesPerBlock, double sampleRate) override;
    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override;
    void reset();
    
    void setBPM(int newBPM);
    
    void setMetGain(float newGain);
    
    
    
    void hiResTimerCallback() override;
    
    
   
   
    
    
private:
    int metTotalSamples { 0 };
    double metSampleRate { 48000 };
    int metInterval { 0 };
    int metBPM { 40 };
    int metNumSamplesRemaining;
    
    
    std::unique_ptr <AudioFormatReaderSource> pMetronomeSample { nullptr }; /* Allows previous samples to be removed from memory (after that sample has been used) */
    AudioFormatManager metaudioFormatManager;
    
   // Audio DeviceSampleRate;
    
    int sliderValue = { 0 };
    
};
