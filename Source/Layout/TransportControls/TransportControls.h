/*
  ==============================================================================

    TransportControls.h
    Created: 23 Jan 2022 1:42:21pm
    Author:  Aaron Ennis

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "./TransportButtons/TransportButtons.h"

class TransportControls : public juce::Component, juce::AudioProcessorValueTreeState::Listener
{
public:
    //==========================================================================
    TransportControls(juce::AudioProcessorValueTreeState& vts, 
                      juce::AudioSampleBuffer* fileBuffer,
                      juce::AudioAppComponent* mainComponent,
                      juce::DialogWindow::LaunchOptions& dialogOptions,
                      juce::AudioThumbnail** thumbnails,
                      juce::AudioDeviceManager& manager);

    ~TransportControls();

    //==========================================================================
    void paint(juce::Graphics& g) override;
    void resized() override;

    void parameterChanged(const juce::String& parameterID, float newValue) override;

private:

    TransportButtons transportButtons;
    juce::TextButton loadTrackButton;

    juce::TextButton audioSettingsButton;
    std::unique_ptr<juce::FileChooser> fileChooser;
    juce::AudioFormatManager formatManager;
    juce::AudioDeviceManager& deviceManager;
    juce::AudioProcessorValueTreeState& parameters;

    void loadTrackButtonClicked(juce::AudioProcessorValueTreeState& vts,
                                juce::AudioSampleBuffer* fileBuffer,
                                juce::AudioAppComponent* mainComponent,
                                juce::AudioThumbnail** thumbnails);

    void audioSettingsButtonClicked(juce::DialogWindow::LaunchOptions& dialogOptions);

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TransportControls)
};