#include <gdal.h>
#include <gdal_priv.h>
#include <iostream>

using namespace std;

int main() {
  cout << "using gdal";
    GDALDataset *poDataset;

    GDALAllRegister();

    // Open a dataset, for example
    poDataset = (GDALDataset *) GDALOpen( "your_dataset.tif", GA_ReadOnly );
    if( poDataset == NULL ) {
        // Handle error
    }

    // Your GDAL operations here

    // Clean up
    GDALClose(poDataset);
    return 0;
}
