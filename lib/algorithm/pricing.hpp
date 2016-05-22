#ifndef PRICING_HPP
#define PRICING_HPP

#include "../models/shipment.hpp"

#define PRICING 2.5

class Pricing
{
public:
    Pricing();
    static double calculateAmount(Shipment *s)
    {
        double desi = (s->getHeight() * s->getWidth() * s->getLength()) / 3000;
        if (desi < s->getWeight()) {
            desi = s->getWeight();
        }
        return desi * PRICING;
    }
};

#endif // PRICING_HPP
