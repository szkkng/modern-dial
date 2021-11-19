#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (600, 400);
    setWantsKeyboardFocus (true);
    juce::LookAndFeel::setDefaultLookAndFeel (&customLookAndFeel);

    blueDial.setColour (juce::Slider::rotarySliderFillColourId, CustomColours::blue);
    greenDial.setColour (juce::Slider::rotarySliderFillColourId, CustomColours::green);
    yellowDial.setColour (juce::Slider::rotarySliderFillColourId, CustomColours::yellow);
    
    addAndMakeVisible (blueDial);
    addAndMakeVisible (greenDial);
    addAndMakeVisible (yellowDial);
}

MainComponent::~MainComponent()
{
    juce::LookAndFeel::setDefaultLookAndFeel (nullptr);
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    g.fillAll (CustomColours::black);
}

void MainComponent::resized()
{
    blueDial.setBounds (120, 160, 80, 80);
    greenDial.setBounds (260, 160, 80, 80);
    yellowDial.setBounds (400, 160, 80, 80);
}
