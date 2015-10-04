#ifndef PARAMETER_H_
#define PARAMETER_H_

// This class is to be used as an abstraction for parameter values.
// The parameter value provided by the user is normalized using
// linear interpolation.
//
// Derived classes can use different forms of interpolation
// by overriding the virtual methods for updating the
// actual and default parameter values and the corresponding
// normalized values.
class Parameter
{
private:
    std::string name_;          // The name of the parameter
    std::string unit_;          // The united used by the parameter
    float normalized_;          // The normalized parameter value
    float parameter_;           // The actual parameter value
    float minimum_;             // The minimum actual parameter value
    float maximum_;             // The maximum actual parameter value
    float default_;             // The actual default parameter value
    float normalized_default_;  // The normalized default value
    
    // Calculates the actual parameter value from
    // the current range and normalized value.
    //
    // This should always be called when minimum_,
    // maximum_, or normalized_ have been changed.
    virtual void UpdateParameter() {
        parameter_  = (1.f - normalized_) * minimum_ + maximum_ * normalized_;
    }
    
    // Calculates the normalized parameter value from
    // the current range and actual value.
    //
    // This should always be called when minimum_,
    // maximum_, or paramter_ have been changed.
    virtual void UpdateNormalized() {
        normalized_ = (parameter_ - minimum_) / (maximum_ - minimum_);
    }
    
    // Calculates the actual default parameter value
    // from the current range and normalized default
    // value.
    //
    // This should always be called when minimum_,
    // maximum_, or normalized_default_ have been changed.
    virtual void UpdateDefault() {
        default_  = (1.f - normalized_default_) * minimum_ + maximum_ * normalized_default_;
    }
    
    // Calculates the normalized default parameter
    // value from the current range and actual default
    // value.
    //
    // This should always be called when minimum_,
    // maximum_, or default_ have been changed.
    virtual void UpdateNormalizedDefault() {
        normalized_default_ = (default_ - minimum_) / (maximum_ - minimum_);
    }
    
    // Updates the minimum and maximum values of
    // the actual parameter value.
    inline void UpdateRange(float minimum, float maximum) {
        minimum_ = minimum;
        maximum_ = maximum;
    };
    
public:
    // Creates a parameter with the given name
    // and unit. If no name or unit is given,
    // empty string will be used instead.
    //
    // This is essentially the default constructor.
    Parameter(std::string name = std::string(),
              std::string unit = std::string()) {
        name_ = name;
        unit_ = unit;
        normalized_ = parameter_ = minimum_ = 0.f;
        maximum_ = 1.f;
        normalized_default_ = default_ = 0.f;
    };
    
    // Default destructor
    virtual ~Parameter() {};
    
    // Creates a parameter with the given name,
    // unit, minimum, and maximum values. The
    // parameter will be set to the minimum value.
    Parameter(std::string name, std::string unit,
              float minimum, float maximum) {
        name_ = name;
        unit_ = unit;
        UpdateRange(minimum, maximum);
        default_ = parameter_  = minimum_;
        normalized_default_ = normalized_ = 0.f;
    };
    
    // Creates a parameter with the given minimum
    // and maximum values. The parameter will be
    // set to the minimum value.
    Parameter(float minimum, float maximum) {
        name_ = std::string();
        unit_ = std::string();
        UpdateRange(minimum, maximum);
        default_ = parameter_  = minimum_;
        normalized_default_ = normalized_ = 0.f;
    };
    
    // Creates a parameter with the given name,
    // unit, minimum, maximum, and default values.
    // The parameter will be set to the default value.
    Parameter(std::string name, std::string unit,
              float minimum, float maximum,
              float default_value) {
        name_       = name;
        unit_       = unit;
        UpdateRange(minimum, maximum);
        default_    = default_value;
        UpdateNormalizedDefault();
        parameter_  = default_;
        normalized_ = normalized_default_;
    };
    
    // Creates a parameter with the given minimum,
    // maximum, and default values. The parameter
    // will be set to the default value.
    Parameter(float minimum, float maximum,
              float default_value) {
        name_       = std::string();
        unit_       = std::string();
        UpdateRange(minimum, maximum);
        default_    = default_value;
        UpdateNormalizedDefault();
        parameter_  = default_;
        normalized_ = normalized_default_;
    };
    
    // Sets the minimum and maximum values of
    // the actual parameter value.
    //
    // It's important to note that the actual
    // parameter and default values will also
    // change to match their corresponding
    // normalized values within the new range.
    // The new actual parameter value will
    // not be set to the new default paramter value.
    void SetRange(float minimum, float maximum) {
        UpdateRange(minimum, maximum);
        UpdateDefault();
        UpdateParameter();
    };
    
    // Sets the actual parameter value to the
    // given user value and returns the newly
    // update normalized parameter value.
    float SetParameter(float user_value) {
        parameter_ = user_value;
        UpdateNormalized();
        return normalized_;
    };
    
    // Sets the normalized parameter value to
    // the given value and returns the newly
    // updated actual parameter value.
    float SetNormalized(float normalized_value) {
        normalized_ = normalized_value;
        UpdateParameter();
        return parameter_;
    };
    
    // Returns the name of the parameter.
    inline std::string name()  { return name_; }
    
    // Returns the unit of the acutal parameter value.
    inline std::string unit()  { return unit_; }
    
    // Returns the current minimum actual parameter value.
    inline float minimum()     { return minimum_; }
    
    // Returns the current maximum actual parameter value.
    inline float maximum()     { return maximum_; }
    
    // Returns the current actual parameter value.
    inline float parameter()   { return parameter_; }
    
    // Returns the current normalized parameter value.
    inline float normalized()  { return normalized_; }
    
    // Returns the actual default parameter value.
    inline float default_value()     { return default_; }
    
    // Returns the normalized default parameter value.
    inline float normalized_default() { return normalized_default_; }
};

#endif  // PARAMETER_H_
