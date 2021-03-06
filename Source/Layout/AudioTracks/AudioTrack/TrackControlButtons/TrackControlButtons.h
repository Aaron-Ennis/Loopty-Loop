/*
  ==============================================================================

    TrackControlButtons.h
    Created: 24 Jan 2022 7:51:52pm
    Author:  Aaron Ennis

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class TrackControlButtons : public juce::Component, juce::AudioProcessorValueTreeState::Listener
{
public:
    //==========================================================================
    TrackControlButtons(int id, juce::AudioProcessorValueTreeState& vts);
    ~TrackControlButtons();

    //==========================================================================
    void paint(juce::Graphics& g) override;
    void resized() override;

    void parameterChanged(const juce::String &parameterID, float newValue) override;

    typedef juce::AudioProcessorValueTreeState::ButtonAttachment ButtonAttachment;

private:
    int trackId;

    std::unique_ptr<juce::ToggleButton> armBtn;
    std::unique_ptr<juce::ToggleButton> muteBtn;
    std::unique_ptr<juce::ToggleButton> revBtn;
    std::unique_ptr<juce::ToggleButton> soloBtn;

    std::unique_ptr<ButtonAttachment> revAttachment;
    std::unique_ptr<ButtonAttachment> muteAttachment;
    std::unique_ptr<ButtonAttachment> armAttachment;
    std::unique_ptr<ButtonAttachment> soloAttachment;

    juce::AudioProcessorValueTreeState& parameters;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TrackControlButtons)
};