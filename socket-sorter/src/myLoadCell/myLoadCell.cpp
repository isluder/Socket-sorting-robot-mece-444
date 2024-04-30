#include "myLoadCell/myLoadCell.h"
#include "myConfig.h"
#include "HX711.h"

bool IS_LOAD_CELL_SET_UP = false;
HX711 scale;
int const average_read = 20;

void set_up_load_cell()
{
    scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
    while (!scale.is_ready()){}
    scale.tare(15);
}

void reset_load_cell()
{
}

float mymap(float x, float in_min, float in_max, float out_min, float out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

float get_weight()
{
    if (IS_LOAD_CELL_SET_UP == false)
    {
        set_up_load_cell();
        IS_LOAD_CELL_SET_UP = true;
    }

    double reading = -scale.get_units(average_read);

    // return reading;
    return mymap(reading, 0.00, 98500.00, 0.00, 141.00);
}