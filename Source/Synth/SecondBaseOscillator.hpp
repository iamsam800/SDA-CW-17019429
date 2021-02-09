//
//  BaseOscillator.hpp
//  JuceAudio - App
//
//  Created by Sam Scott on 15/01/2021.
//  Copyright © 2021 UWE. All rights reserved.
//

#pragma once
#define _USE_MATH_DEFINES

/*/Users/samscott/Desktop/JuceSDA/Practical 6/JuceAudio/Builds/MacOSX/BaseOscillator.hpp */


#include <JuceHeader.h>
#include <cmath>


/** Class for the base class oscillator with gain controls. Call nextSample() repetedly to stream audio samples from the oscilator. */

class BaseOscillatorTwo
{
public:
    /** BaseOscillator constructor */
    BaseOscillatorTwo();
    
    /** BaseOscillator destructor */
    virtual ~BaseOscillatorTwo() = default;
    
    /** Sets the oscillator frequency.
     @param newFrequency  specifies the oscilator frequency
     @see setNote()*/
    void setFrequency (float newFrequency);
    
    /** Sets the oscillator frequency using a midi note number.
     @param noteNumber  MIDI note number (0 - 127)
     @see setFrequency()*/
    void setNote (int noteNumber);
    
    /** Sets the oscillator gain.
     @param newGain  the new gain value */
    void setGain (float newGain);
    
    /** Sets the sample rate.
     @param newSampleRate  new sample rate */
    void setSampleRate (float newSampleRate);
    
    /** Returns the next sample value
     @return the next oscillator sample */
    float nextSample();
    
    float getFrequency(float currentFrequency); 
    
    void setPitchBend(float Value);
    
    
    
    
    
    
protected:
    /** Generates the actual waveshape from a given phase value. This should not be called directly it is used internally by nextSample()
     @param phase argument in the range 0 - 2pi
     @return amplitude value for the given phase */
    virtual  float renderWaveShape (float currentphase);
    float frequency {0.f};
    float phase             {0.f};
    std::atomic<float>  gain              {0.f};
    std::atomic<float> sampleRate        {44100.f};
    std::atomic<float> phaseIncrement    {0.f};
    std::atomic<float> pitchBendValue {0.f};
    
    
    /**  std::atomic<float> sampleRate = 44100.f;
     */
     
     private:
     /** Updates the internal state for the current sample rate and frequency. */
    void updatePhaseIncrement();
    
    
    
};

