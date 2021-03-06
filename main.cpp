//
//  main.cpp
//  LLTemplate
//
//  Created by James Shockey on 12/6/16.
//  Copyright © 2016 James Shockey. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cmath> 
#include <string>
#include <stdlib.h>
#include "slist.h"

using namespace std;

class Airport
{
public:
    char    code[5];
    double   longitude;
    double   latitude;
    
};



void simpleSort(Airport* aus, int airportCount, Airport* airportArr[]);
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);

int main()
{
    ifstream infile;
    int i=0;
    char cNum[10] ;
    Airport* airportArr[13500];
    int   airportCount;
    //Airport* a[13500];
    
	infile.open ("./USAirportCodes.csv", ifstream::in);

    if (infile.is_open())
    {
		int   c=0;
        while (infile.good())
        {
            airportArr[c] = new Airport();
            infile.getline(airportArr[c]->code, 256, ',');
            infile.getline(cNum, 256, ',');
            airportArr[c]->longitude = atof(cNum);
            infile.getline(cNum, 256, '\n');
            airportArr[c]->latitude = atof(cNum);

           /* if (!(c % 1000))
                cout << airportArr[c]->code << " long: " << airportArr[c]->longitude << " lat: " << airportArr[c]->latitude <<  endl;

            
            if (!(c % 1000))
            {
                cout << airportArr[c]->code << " long: " << airportArr[c]->longitude << " lat: " << airportArr[c]->latitude <<  endl;
                cout << airportArr[c+1]->code << endl; //" long: " << airportArr[c+1]->longitude << " lat: " << airportArr[c+1]->latitude <<  endl;                               
            }
            */

            
            i++ ;
            c++;
        }
        airportCount = c-1;
        infile.close();
        
         /*for (int c=0; c < airportCount; c++)
            if (!(c % 1000))
            {
                cout << airportArr[c]->code << " long: " << airportArr[c]->longitude << " lat: " << airportArr[c]->latitude <<  endl;
                cout << airportArr[c+1]->code << " long: " << airportArr[c+1]->longitude << " lat: " << airportArr[c+1]->latitude <<  endl;
                cout <<"Distance between " << airportArr[c]->code << " and " << airportArr[c+1]->code << " is "
                  << distanceEarth( airportArr[c]->longitude, airportArr[c]->latitude , airportArr[c+1]->longitude, airportArr[c+1]->latitude) << endl;
            }*/
    }
    else
    {
        cout << "Error opening file";
    }
 
   // Initialize Linked List
   
   //List<Airport> a;
   
   cout << "Count: " << airportCount << endl;
   
   Airport* austin = airportArr[10655];
   
   cout << austin->code;
   simpleSort(austin, airportCount, airportArr);
   Airport* farthest;
   
    ofstream output;
	output.open("sorted.csv");
	Airport* a;
	string write;
	for(int z = 0; z < airportCount; z++)
	{
		a = airportArr[z];
		output << "" << a->code << "," << a->latitude << "," << a->longitude << "," << distanceEarth(a->latitude, a->longitude, austin->latitude, austin->longitude) << "\n";
	}
   
   output.close();
   
   //double farthestDis = 0;
   double dis;
   
      double farthestDis = distanceEarth(airportArr[0]->latitude, airportArr[0]->longitude, austin->latitude, austin->longitude);

      cout << "Farthest Airport: " << airportArr[0]->code << " distance: " << farthestDis << endl;

   for(int i = 1000; i < 13423; i++)
   {
	   dis = distanceEarth(airportArr[i]->latitude, airportArr[i]->longitude, austin->latitude, austin->longitude);
	   if (dis < 100)
	   {
		   cout << airportArr[i]->code << " " << dis << endl;
	   }
	   
	   if(dis > farthestDis)
	   {
		   cout << "!";
		   farthest = airportArr[i];
		   farthestDis = dis;
	   }
   }
   
   /*cout << endl << endl;
   
   cout << "Farthest Airport: " << farthest->code << " distance: " << farthestDis << endl;*/

}



#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

// This function converts decimal degrees to radians
double deg2rad(double deg) {
  return (deg * pi / 180);
}

//  This function converts radians to decimal degrees
double rad2deg(double rad) {
  return (rad * 180 / pi);
}


/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(lat2d);
  lon2r = deg2rad(lon2d);
  u = sin((lat2r - lat1r)/2);
  v = sin((lon2r - lon1r)/2);
  return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}

void simpleSort(Airport* aus, int airportCount, Airport* airportArr[])
{
	Airport* temp;
	for (int i=0; i < airportCount; i++)
	{	
		for (int j=i; j < airportCount; j++)
		{
			if (distanceEarth(airportArr[i]->latitude, airportArr[i]->longitude, aus->latitude, aus->longitude) < distanceEarth(airportArr[j]->latitude, airportArr[j]->longitude, aus->latitude, aus->longitude))
			//total pointed at by i > total pointed at by j
			{
				//swap pointer to record I with pointer to record j
				temp = airportArr[i];
				airportArr[i] = airportArr[j];
				airportArr[j] = temp;
			}
		}
	}
}
