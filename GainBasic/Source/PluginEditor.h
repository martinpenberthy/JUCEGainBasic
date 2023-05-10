/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.
 
    Martin Penberthy
    5/10/2023
    Gain Module
  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class GainBasicAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    GainBasicAudioProcessorEditor (GainBasicAudioProcessor&);
    ~GainBasicAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::Slider sliderGain;//Volume slider
    juce::Label labelGain; //Volume label
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> sliderAttachmentGain;
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    GainBasicAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GainBasicAudioProcessorEditor)
};
