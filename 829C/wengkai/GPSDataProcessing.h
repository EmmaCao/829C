//
//  GPSDataProcessing.h
//  829C
//
//  Created by Emma on 2019/5/21.
//  Copyright © 2019 Emma. All rights reserved.
//

#ifndef GPSDataProcessing_h
#define GPSDataProcessing_h

#include <stdio.h>

//校验读入的GPRMC数据书否正确
int isgprmc(char *p);

void GPSDataProcessing(void);

#endif /* GPSDataProcessing_h */
