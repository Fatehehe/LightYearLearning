#pragma once
#include <SFML/Graphics.hpp>

namespace ly{
    sf::Vector2f RotationToVector(float rotation);
    float DegreesToRadians(float degrees);
    float RadianToDegrees(float radians);

    template<typename T>
    float GetVectorLength(const sf::Vector2<T>& vector){
        return std::sqrt(vector.x * vector.x + vector.y * vector.y);
    }

    template<typename T>
    sf::Vector2<T>& ScaleVector(sf::Vector2<T>& vectorToScale, float amt){
        vectorToScale.x *= amt;
        vectorToScale.y *= amt;
        return vectorToScale;
    }

    template<typename T>
    sf::Vector2<T>& Normalized(sf::Vector2<T>& vector)
    {
        float vectorLength = GetVectorLength<T>(vector);

        if (vectorLength == 0.f)
        {
            vector = sf::Vector2<T>{ 0, 0 };
            return vector; 
        }

        ScaleVector(vector, 1.f / vectorLength);
        return vector;
    }

}