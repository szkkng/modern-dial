/*
  ==============================================================================

    ModernDial.cpp
    Created: 23 Jul 2021 12:45:48pm
    Author:  Kengo Suzuki

  ==============================================================================
*/

#include "ModernDial.h"

ModernDial::ModernDial()
{
    setSliderStyle (juce::Slider::SliderStyle::RotaryVerticalDrag);
    setRotaryParameters (juce::MathConstants<float>::pi * 1.25f,
                         juce::MathConstants<float>::pi * 2.75f,
                         true);
    setColour (juce::Slider::textBoxTextColourId,    CustomColours::blackGrey);
    setColour (juce::Slider::textBoxOutlineColourId, CustomColours::grey);
    setLookAndFeel (&customLookAndFeel);
    setVelocityBasedMode (true);
    setVelocityModeParameters (0.5, 1, 0.09, false);
    setRange (0.0, 100.0, 0.01);
    setValue (50.0);
    setDoubleClickReturnValue (true, 50.0);
    setWantsKeyboardFocus (true);
    setTextValueSuffix (" %");
    onValueChange = [&]()
    {
        if (getValue() < 10)
            setNumDecimalPlacesToDisplay (2);
        else if (10 <= getValue() && getValue() < 100)
            setNumDecimalPlacesToDisplay (1);
        else
            setNumDecimalPlacesToDisplay (0);
    };
}

ModernDial::~ModernDial()
{
    setLookAndFeel (nullptr);
}

void ModernDial::paint (juce::Graphics& g)
{
    juce::Slider::paint (g);

    if (hasKeyboardFocus (true))
    {
        auto bounds = getLocalBounds().toFloat();
        auto len    = juce::jmin (bounds.getHeight(), bounds.getWidth()) * 0.07f;
        auto thick  = len * 0.5f;
        
        auto topLeft     = bounds.getTopLeft();
        auto topRight    = bounds.getTopRight();
        auto bottomLeft  = bounds.getBottomLeft();
        auto bottomRight = bounds.getBottomRight();
        
        g.setColour (findColour (juce::Slider::textBoxOutlineColourId));
        
        juce::Path topLeftPath;
        topLeftPath.startNewSubPath (topLeft);
        topLeftPath.lineTo (topLeft.x, topLeft.y + len);
        topLeftPath.startNewSubPath (topLeft);
        topLeftPath.lineTo (topLeft.x + len, topLeft.y);
        g.strokePath (topLeftPath, juce::PathStrokeType (thick));
        
        juce::Path topRightPath;
        topRightPath.startNewSubPath (topRight);
        topRightPath.lineTo (topRight.x, topRight.y + len);
        topRightPath.startNewSubPath (topRight);
        topRightPath.lineTo (topRight.x - len, topRight.y);
        g.strokePath (topRightPath, juce::PathStrokeType (thick));
        
        juce::Path bottomLeftPath;
        bottomLeftPath.startNewSubPath (bottomLeft);
        bottomLeftPath.lineTo (bottomLeft.x, bottomLeft.y - len);
        bottomLeftPath.startNewSubPath (bottomLeft);
        bottomLeftPath.lineTo (bottomLeft.x + len, bottomLeft.y);
        g.strokePath (bottomLeftPath, juce::PathStrokeType (thick));
        
        juce::Path bottomRightPath;
        bottomRightPath.startNewSubPath (bottomRight);
        bottomRightPath.lineTo (bottomRight.x, bottomRight.y - len);
        bottomRightPath.startNewSubPath (bottomRight);
        bottomRightPath.lineTo (bottomRight.x - len, bottomRight.y);
        g.strokePath (bottomRightPath, juce::PathStrokeType (thick));
    }
}

void ModernDial::mouseDown (const juce::MouseEvent& event)
{
    juce::Slider::mouseDown (event);

    setMouseCursor (juce::MouseCursor::NoCursor);
}

void ModernDial::mouseUp (const juce::MouseEvent& event)
{
    juce::Slider::mouseUp (event);

    juce::Desktop::getInstance().getMainMouseSource().setScreenPosition (event.source.getLastMouseDownPosition());
    
    setMouseCursor (juce::MouseCursor::NormalCursor);
}

bool ModernDial::keyPressed (const juce::KeyPress& k)
{
    char numChars[] = "0123456789";

    for (auto numChar : numChars)
    {
        if (k.isKeyCode (numChar))
        {
            CustomLookAndFeel::CustomLabel::initialPressedKey = juce::String::charToString (numChar);
            showTextBox();

            return true;
        }
    }

    return false;
}
