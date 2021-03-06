/*
  ==============================================================================

    PlayButton.cpp
    Created: 26 Jan 2022 1:59:12pm
    Author:  Aaron Ennis

  ==============================================================================
*/

#include "PlayButton.h"

//==============================================================================
PlayButton::PlayButton(juce::String& name, juce::Colour normalColour, juce::Colour overColour, juce::Colour downColour) 
    : ShapeButton(name, normalColour, overColour, downColour)
{
    //========================================================================== 
    // Define the path for the button shape
    juce::Path playPath;
    auto localBounds = this->getLocalBounds();
    playPath.addTriangle(localBounds.getY() - 5.0f, localBounds.getX() - 5.0f,
                         localBounds.getY() - 5.0f, localBounds.getHeight() + 5.0f,
                         localBounds.getWidth() + 5.0f, localBounds.getHeight() / 2.0f);

    this->setShape(playPath, true, true, false);
    //==========================================================================
}

PlayButton::~PlayButton()
{

}

void PlayButton::resized()
{

}