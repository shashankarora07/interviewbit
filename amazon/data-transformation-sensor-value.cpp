#include <limits.h> 
#include <stdint.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <inttypes.h> 
#include <stdbool.h> 
#include <math.h> 
 
/* INPUT

9
0x00 0x01 0x02 0x03 0x04 0x00 0x00 0x00 0x00
33

9
0x02 0x01 0x02 0x03 0x04 0x00 0x00 0x00 0x00
33

9
0x82 0x01 0x02 0x03 0x04 0x00 0x00 0x00 0xAB
33

*/


typedef enum  
{ 
  STATUS_SUCCESS, 
  STATUS_BAD_POINTER, 
  STATUS_BAD_ARRAY_LENGTH, 
  STATUS_NO_SENSOR_DATA, 
} FuncStatus_t; 

FuncStatus_t TransformData( 
    const size_t inputDataLength, 
    const uint8_t inputDataValues[], 
    const size_t outputDataLength, 
    uint8_t outputDataValues[]) 
{ 
    /* Stub */ 

    uint8_t countValidSensor = 0;
    uint8_t start = 1;

    for (auto i = 0; i < sizeof(uint8_t) * 8; i++)
    {
        uint8_t bitStatus = inputDataValues[0] & (1 << i);
        uint32_t ValidSensorOutput = 0;
        //printf("bitStatus = %d\n", bitStatus);
        if (bitStatus)
        {
            countValidSensor++;
            ValidSensorOutput = inputDataValues[i + 1] * pow(2,i);
            memcpy(outputDataValues + start + (sizeof(uint32_t) * i), &ValidSensorOutput, sizeof(uint32_t));
        }
        else
        {
            ValidSensorOutput = 0;
            memcpy(outputDataValues + start + (sizeof(uint32_t) * i), &ValidSensorOutput, sizeof(uint32_t));
        }
    }

    outputDataValues[0] = countValidSensor;

    if ((inputDataValues[0] & 0xFF) == 0)
        return STATUS_NO_SENSOR_DATA;

    return STATUS_SUCCESS; 
} 

const char *FuncStatusString[4] = { 
    "STATUS_SUCCESS", 
    "STATUS_BAD_POINTER", 
    "STATUS_BAD_ARRAY_LENGTH", 
    "STATUS_NO_SENSOR_DATA" 
};


int main() { 

    int status = -1; 
    size_t  inputDataLength = 0; 
    uint8_t* inputDataValues = NULL; 
    size_t outputDataLength = 0; 
    uint8_t* outputDataValues = NULL; 
    uint8_t expectedOutputDataLength = 0; 
    bool null_input_array = false; 
    FuncStatus_t result = STATUS_SUCCESS; 


    char line[1024]; 

    // Read inputDataLength values 
    if (fgets(line, sizeof(line), stdin) == NULL) { 
        printf("Error occured at line %d of test code.\n", __LINE__); 
        goto exit; 
    }      

    if (1 != sscanf(line, "%2zu", &inputDataLength)) { 
        printf("Error occured at line %d of test code.\n", __LINE__); 
        goto exit; 
    }      

    if (inputDataLength <= 0) { 
        printf("Error occured at line %d of test code.\n", __LINE__); 
        goto exit; 
    }    

    // Allocate both input and output buffers 
    inputDataValues = (uint8_t *)calloc(inputDataLength, sizeof(uint8_t)); 

    if (inputDataValues == NULL) { 
        printf("Error occured at line %d of test code.\n", __LINE__); 
        goto exit; 
    } 

     

    expectedOutputDataLength = sizeof(uint32_t) * (inputDataLength - 1) + sizeof(uint8_t); 
    outputDataValues = (uint8_t *)calloc(expectedOutputDataLength, 1); 

    if (outputDataValues == NULL) { 
        printf("Error occured at line %d of test code.\n", __LINE__); 
        goto exit; 

    }

    // Read inputDataValues values 
    if (fgets(line, sizeof(line), stdin) == NULL) { 
       printf("Error occured at line %d of test code.\n", __LINE__); 
        goto exit; 
    }

    if (strncmp(line, "NULL", 4) == 0) { 
        null_input_array = true; 
    } 
    else { 

        char *curbuf = line; 

        for (size_t i = 0; i < inputDataLength; i++) { 

            unsigned int tempValue = 0; 
            if (1 != sscanf(curbuf, "0x%2x", &tempValue)) { 
                printf("Error occured at line %d of test code.\n", __LINE__);
                goto exit; 
            } 
            inputDataValues[i] = (uint8_t)tempValue; 

            curbuf += 5; 
        } 

    } 

    // Read outputDataLength value  
    if (fgets(line, sizeof(line), stdin) == NULL) { 
        printf("Error occured at line %d of test code.\n", __LINE__); 
        goto exit; 

    }    

    if (1 != sscanf(line, "%2zu", &outputDataLength)) { 
        printf("Error occured at line %d of test code.\n", __LINE__); 
        goto exit; 
    }

    result = TransformData( 
        inputDataLength, 
        null_input_array ? NULL : inputDataValues, 
        outputDataLength, 
        outputDataValues);

    //Output results for verification 
    printf("%s\n", FuncStatusString[result]);

    if (result == STATUS_SUCCESS) { 
        if (outputDataLength > 33) { 
            outputDataLength = 33;
        }

        for (size_t i = 0; i < outputDataLength; i++) { 
            printf("0x%.2x ", outputDataValues[i]); 
        }
        printf("\n");
    }
    status = 0;  

exit: 
    if (inputDataValues != NULL) 
        free(inputDataValues);   

    if (outputDataValues != NULL) 
       free(outputDataValues);

    return status; 

} 