void computeForward(){
  if(abs(rxValue) < 50) rxValue = 0 ; 
  if(abs(ryValue) < 50) ryValue = 0 ;

  if (rxValue != 0 ||ryValue != 0) {
    if (abs(ryValue) <= 127 ) inv_yR = 127;    
    atanVal = atan2(rxValue, inv_yR);
    atanVal = (atanVal* 3 * 180 / PI);
    teta = (atanVal*-1) * 400;
    // Serial.printf("rx:%4d,ry:%4d", inverse, ry_val);
    // Serial.println();
  }

  if (lxValue != 0 || lyValue != 0) {
      x = lxValue * 225 / 128;
      y = lyValue * 225 / 128;
      
      if(abs(x) < 50){
        x = 0 ;
      }if(abs(y) < 50){
        y = 0 ;
      }
      if (abs(y) > abs(x)) {
        if (abs(y) > 60) x = 0;
      } else {
        if (abs(x) > 60) y = 0;
      }
    
  
  if(abs(x) < 10) x = 0;
  if(abs(y) < 10) y = 0;

  }

} 
