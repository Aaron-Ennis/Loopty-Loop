/*
  ==============================================================================

    RewindButton.cpp
    Created: 26 Jan 2022 2:00:16pm
    Author:  aaron

  ==============================================================================
*/

#include "RewindButton.h"

//==============================================================================
RewindButton::RewindButton(juce::String& name, juce::Colour normalColour, juce::Colour overColour, juce::Colour downColour) : ShapeButton(name, normalColour, overColour, downColour)
{
    //========================================================================== 
    // Define the path for the button shape
    juce::Path rewindPath;
    auto localOrigin = this->getPosition();
    auto localBounds = this->getLocalBounds();
    rewindPath.addTriangle(localOrigin.getX() + 5.0f, localOrigin.getY() + 5.0f,
                           localOrigin.getX() + 5.0f, localBounds.getHeight() - 5.0f,
                           localBounds.getWidth() - 5.0f, localBounds.getHeight() / 2.0f);

    this->setShape(rewindPath, true, true, false);
    //==========================================================================

}

RewindButton::~RewindButton()
{

}

void RewindButton::resized()
{

}