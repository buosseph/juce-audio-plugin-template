/*
  ==============================================================================

    Parameter.h
    Created: 3 Jun 2015 5:05:48pm
    Author:  Brian Uosseph

  ==============================================================================
*/

#ifndef PARAMETER_H_INCLUDED
#define PARAMETER_H_INCLUDED

/**
 * This class is to be used as an abstraction for parameter values.
 * The parameter value provided by the user is normalized using linear interpolation.
 * The values entered for the ranges are the true parameter values
 * (e.g. minimum = -50, maximum = 50).
 */
 
class Parameter
{
    private:
        float userParameter, normalizedParameter, minimum, maximum;

        void updateUserParameter()
        {
            userParameter = minimum + (maximum - minimum) * normalizedParameter;
        };
        void updateVstParameter()
        {
            normalizedParameter = (userParameter - minimum) / (maximum - minimum);
        };

    public:
        Parameter()
        {
            minimum = normalizedParameter = userParameter = 0.f;
            maximum = 1.f;
        };
        Parameter(float minimum, float maximum)
        {
            minimum = minimum;
            maximum = maximum;
        };
        Parameter(float minimum, float maximum, float normalizedValue)
        {
            setRange(minimum, maximum);
            setWithNormalizedValue(normalizedValue);
        };
        
        void setRange(float minimum, float maximum)
        {
            minimum = minimum;
            maximum = maximum;
        };
        float setWithNormalizedValue(float noramlizedValue)
        {
            normalizedParameter = noramlizedValue;
            updateUserParameter();
            return userParameter;
        };
        float setWithUserValue(float userValue)
        {
            userParameter = userValue;
            updateNormalizedParameter();
            return normalizedParameter;
        };
        float getUserParameter() { return userParameter; };
        float getNormalizedParameter() { return normalizedParameter; };
};

#endif  // PARAMETER_H_INCLUDED
