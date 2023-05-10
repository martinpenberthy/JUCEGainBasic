/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

    Martin Penberthy
    5/10/2023
    Gain Module
  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GainBasicAudioProcessorEditor::GainBasicAudioProcessorEditor (GainBasicAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    addAndMakeVisible(sliderGain);
    
    sliderGain.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    //sliderGain.setRange(-96.0f, 48.0f, 1.0f);
    sliderGain.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 76, 38);
    sliderGain.setDoubleClickReturnValue(true, 0.0f);
    sliderGain.setColour(juce::Slider::ColourIds::thumbColourId, juce::Colours::black.withAlpha(0.0f));
    sliderGain.setColour(juce::Slider::ColourIds::rotarySliderFillColourId, juce::Colours::whitesmoke.withAlpha(0.25f));
    sliderGain.setColour(juce::Slider::ColourIds::rotarySliderOutlineColourId, juce::Colours::black.withAlpha(0.25f));
    sliderGain.setColour(juce::Slider::ColourIds::textBoxTextColourId, juce::Colours::whitesmoke.withAlpha(0.25f));
    sliderGain.setColour(juce::Slider::ColourIds::textBoxOutlineColourId, juce::Colours::black.withAlpha(0.0f));
    
    sliderGain.onValueChange = [this]()
    {
        //audioProcessor.volume.setTargetValue(sliderGain.getValue());
        audioProcessor.gain = sliderGain.getValue();
    };
    
   sliderAttachmentGain = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "GAIN", sliderGain);
    
}

GainBasicAudioProcessorEditor::~GainBasicAudioProcessorEditor()
{
}

//==============================================================================
void GainBasicAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::black);

}

void GainBasicAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    sliderGain.setBounds(getWidth()/2 - 100, getHeight()/2 - 100, 200, 200);
}
