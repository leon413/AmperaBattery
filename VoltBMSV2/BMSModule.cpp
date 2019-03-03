#include "config.h"
#include "BMSModule.h"
#include "BMSUtil.h"
#include "Logger.h"


BMSModule::BMSModule()
{
  for (int i = 0; i < 32; i++)
  {
    cellVolt[i] = 0.0f;
    lowestCellVolt[i] = 5.0f;
    highestCellVolt[i] = 0.0f;
  }
  moduleVolt = 0.0f;
  temperatures[0] = 0.0f;
  temperatures[1] = 0.0f;
  temperatures[2] = 0.0f;
  temperatures[3] = 0.0f;
  temperatures[4] = 0.0f;

  lowestTemperature = 200.0f;
  highestTemperature = -100.0f;
  lowestModuleVolt = 200.0f;
  highestModuleVolt = 0.0f;
  exists = false;
  moduleAddress = 0;
}

void BMSModule::clearmodule()
{
  for (int i = 0; i < 32; i++)
  {
    cellVolt[i] = 0.0f;
  }
  moduleVolt = 0.0f;
  temperatures[0] = 0.0f;
  temperatures[1] = 0.0f;
  temperatures[2] = 0.0f;
  temperatures[3] = 0.0f;
  temperatures[4] = 0.0f;
  exists = false;
  moduleAddress = 0;
}

void BMSModule::decodecan(int Id, CAN_message_t &msg)
{
  switch (Id)
  {
    case 1:
      cellVolt[1] = float(((msg.buf[0] & 0x0F) << 8  + msg.buf[1]) * 0.00125);
      cellVolt[2] = float(((msg.buf[2] & 0x0F) << 8  + msg.buf[3]) * 0.00125);
      cellVolt[3] = float(((msg.buf[4] & 0x0F) << 8  + msg.buf[5]) * 0.00125);
      cellVolt[4] = float(((msg.buf[6] & 0x0F) << 8  + msg.buf[7]) * 0.00125);
      break;

    case 2:
      cellVolt[5] = float(((msg.buf[0] & 0x0F) << 8  + msg.buf[1]) * 0.00125);
      cellVolt[6] = float(((msg.buf[2] & 0x0F) << 8  + msg.buf[3]) * 0.00125);
      cellVolt[7] = float(((msg.buf[4] & 0x0F) << 8  + msg.buf[5]) * 0.00125);
      cellVolt[8] = float(((msg.buf[6] & 0x0F) << 8  + msg.buf[7]) * 0.00125);
      break;

    case 3:
      cellVolt[9] = float(((msg.buf[0] & 0x0F) << 8  + msg.buf[1]) * 0.00125);
      cellVolt[10] = float(((msg.buf[2] & 0x0F) << 8  + msg.buf[3]) * 0.00125);
      cellVolt[11] = float(((msg.buf[4] & 0x0F) << 8  + msg.buf[5]) * 0.00125);
      cellVolt[12] = float(((msg.buf[6] & 0x0F) << 8  + msg.buf[7]) * 0.00125);
      break;

    case 4:
      cellVolt[13] = float(((msg.buf[0] & 0x0F) << 8  + msg.buf[1]) * 0.00125);
      cellVolt[14] = float(((msg.buf[2] & 0x0F) << 8  + msg.buf[3]) * 0.00125);
      cellVolt[15] = float(((msg.buf[4] & 0x0F) << 8  + msg.buf[5]) * 0.00125);
      cellVolt[16] = float(((msg.buf[6] & 0x0F) << 8  + msg.buf[7]) * 0.00125);
      break;

    case 5:
      cellVolt[17] = float(((msg.buf[0] & 0x0F) << 8  + msg.buf[1]) * 0.00125);
      cellVolt[18] = float(((msg.buf[2] & 0x0F) << 8  + msg.buf[3]) * 0.00125);
      cellVolt[19] = float(((msg.buf[4] & 0x0F) << 8  + msg.buf[5]) * 0.00125);
      cellVolt[20] = float(((msg.buf[6] & 0x0F) << 8  + msg.buf[7]) * 0.00125);
      break;

    case 6:
      cellVolt[21] = float(((msg.buf[0] & 0x0F) << 8  + msg.buf[1]) * 0.00125);
      cellVolt[22] = float(((msg.buf[2] & 0x0F) << 8  + msg.buf[3]) * 0.00125);
      cellVolt[23] = float(((msg.buf[4] & 0x0F) << 8  + msg.buf[5]) * 0.00125);
      cellVolt[24] = float(((msg.buf[6] & 0x0F) << 8  + msg.buf[7]) * 0.00125);
      break;

    case 7:
      cellVolt[25] = float(((msg.buf[0] & 0x0F) << 8  + msg.buf[1]) * 0.00125);
      cellVolt[26] = float(((msg.buf[2] & 0x0F) << 8  + msg.buf[3]) * 0.00125);
      cellVolt[27] = float(((msg.buf[4] & 0x0F) << 8  + msg.buf[5]) * 0.00125);
      cellVolt[28] = float(((msg.buf[6] & 0x0F) << 8  + msg.buf[7]) * 0.00125);
      break;

    case 8:
      cellVolt[29] = float(((msg.buf[0] & 0x0F) << 8  + msg.buf[1]) * 0.00125);
      cellVolt[30] = float(((msg.buf[2] & 0x0F) << 8  + msg.buf[3]) * 0.00125);
      cellVolt[31] = float(((msg.buf[4] & 0x0F) << 8  + msg.buf[5]) * 0.00125);
      cellVolt[32] = float(((msg.buf[6] & 0x0F) << 8  + msg.buf[7]) * 0.00125);
      break;

    case 11:
      temperatures[0] = float((((msg.buf[0] & 0x03) << 8 + msg.buf[1]) * 0.0556) - 27.778);
      break;
    case 12:
      temperatures[1] = float((((msg.buf[0] & 0x03) << 8 + msg.buf[1]) * 0.0556) - 27.778);
      temperatures[2] = float((((msg.buf[0] & 0x03) << 8 + msg.buf[1]) * 0.0556) - 27.778);
      break;
    case 13:
      temperatures[3] = float((((msg.buf[0] & 0x03) << 8 + msg.buf[1]) * 0.0556) - 27.778);
      break;
    case 14:
      temperatures[5] = float((((msg.buf[0] & 0x03) << 8 + msg.buf[1]) * 0.0556) - 27.778);
      break;

    default:

      break;
  }
  if (getLowTemp() < lowestTemperature) lowestTemperature = getLowTemp();
  if (getHighTemp() > highestTemperature) highestTemperature = getHighTemp();

  for (int i = 0; i < 32; i++)
  {
    if (lowestCellVolt[i] > cellVolt[i] && cellVolt[i] >= IgnoreCell)
    {
      lowestCellVolt[i] = cellVolt[i];
    }
    if (highestCellVolt[i] < cellVolt[i])
    {
      highestCellVolt[i] = cellVolt[i];
    }
  }
}


uint8_t BMSModule::getFaults()
{
  return faults;
}

uint8_t BMSModule::getAlerts()
{
  return alerts;
}

uint8_t BMSModule::getCOVCells()
{
  return COVFaults;
}

uint8_t BMSModule::getCUVCells()
{
  return CUVFaults;
}


float BMSModule::getCellVoltage(int cell)
{
  if (cell < 0 || cell > 32) return 0.0f;
  return cellVolt[cell];
}

float BMSModule::getLowCellV()
{
  float lowVal = 10.0f;
  for (int i = 0; i < 32; i++) if (cellVolt[i] < lowVal && cellVolt[i] > IgnoreCell) lowVal = cellVolt[i];
  return lowVal;
}

float BMSModule::getHighCellV()
{
  float hiVal = 0.0f;
  for (int i = 0; i < 32; i++)
    if (cellVolt[i] > IgnoreCell && cellVolt[i] < 60.0)
    {
      if (cellVolt[i] > hiVal) hiVal = cellVolt[i];
    }
  return hiVal;
}

float BMSModule::getAverageV()
{
  int x = 0;
  float avgVal = 0.0f;
  for (int i = 0; i < 32; i++)
  {
    if (cellVolt[i] > IgnoreCell && cellVolt[i] < 60.0)
    {
      x++;
      avgVal += cellVolt[i];
    }
  }

  scells = x;
  avgVal /= x;
  return avgVal;
}

int BMSModule::getscells()
{
  return scells;
}

float BMSModule::getHighestModuleVolt()
{
  return highestModuleVolt;
}

float BMSModule::getLowestModuleVolt()
{
  return lowestModuleVolt;
}

float BMSModule::getHighestCellVolt(int cell)
{
  if (cell < 0 || cell > 32) return 0.0f;
  return highestCellVolt[cell];
}

float BMSModule::getLowestCellVolt(int cell)
{
  if (cell < 0 || cell > 32) return 0.0f;
  return lowestCellVolt[cell];
}

float BMSModule::getHighestTemp()
{
  return highestTemperature;
}

float BMSModule::getLowestTemp()
{
  return lowestTemperature;
}

float BMSModule::getLowTemp()
{
  if (getAvgTemp() > 0.5)
  {
    if (temperatures[0] > 0.5)
    {
      if (temperatures[0] < temperatures[1] && temperatures[0] < temperatures[2])
      {
        return (temperatures[0]);
      }
    }
    if (temperatures[1] > 0.5)
    {
      if (temperatures[1] < temperatures[0] && temperatures[1] < temperatures[2])
      {
        return (temperatures[1]);
      }
    }
    if (temperatures[2] > 0.5)
    {
      if (temperatures[2] < temperatures[1] && temperatures[2] < temperatures[0])
      {
        return (temperatures[2]);
      }
    }
  }
}

float BMSModule::getHighTemp()
{
  return (temperatures[0] < temperatures[1]) ? temperatures[1] : temperatures[0];
}

float BMSModule::getAvgTemp()
{
  if (sensor == 0)
  {
    float avg = 0;
    int g  = 0;
    for (int i = 0; i < 5; i++)
    {
      if (temperatures[i] > -20 && temperatures[i] < 150)
      {
        avg = avg + temperatures[i];
        g ++;
      }
      avg = avg / g;
    }

    return avg;
    /*
      if (((temperatures[0] + temperatures[1] + temperatures[2]) / 3.0f ) > 0.5)
      {
      if (temperatures[0] > 0.5 && temperatures[1] > 0.5 && temperatures[2] > 0.5)
      {
        return ((temperatures[0] + temperatures[1] + temperatures[2]) / 3.0f);
      }
      if (temperatures[0] < 0.5 && temperatures[1] > 0.5 && temperatures[2] > 0.5)
      {
        return (temperatures[1] + temperatures[2]) / 2.0f;
      }
      if (temperatures[0] > 0.5 && temperatures[1] < 0.5 && temperatures[2] > 0.5)
      {
        return (temperatures[0] + temperatures[2]) / 2.0f;
      }
      if (temperatures[0] > 0.5 && temperatures[1] > 0.5 && temperatures[2] < 0.5)
      {
        return (temperatures[0] + temperatures[1]) / 2.0f;
      }
      if (temperatures[0] > 0.5 && temperatures[1] < 0.5 && temperatures[2] < 0.5)
      {
        return (temperatures[0]);
      }
      if (temperatures[0] < 0.5 && temperatures[1] > 0.5 && temperatures[2] < 0.5)
      {
        return (temperatures[1]);
      }
      if (temperatures[0] < 0.5 && temperatures[1] < 0.5 && temperatures[2] > 0.5)
      {
        return (temperatures[2]);
      }
      if (temperatures[0] < 0.5 && temperatures[1] < 0.5 && temperatures[2] < 0.5)
      {
        return (-80);
      }
      }
    */
  }
  else
  {
    return temperatures[sensor - 1];
  }
}

float BMSModule::getModuleVoltage()
{
  moduleVolt = 0;
  for (int I; I < 32; I++)
  {
    if (cellVolt[I] > IgnoreCell && cellVolt[I] < 60.0)
    {
      moduleVolt = moduleVolt + cellVolt[I];
    }
  }
  return moduleVolt;
}

float BMSModule::getTemperature(int temp)
{
  if (temp < 0 || temp > 2) return 0.0f;
  return temperatures[temp];
}

void BMSModule::setAddress(int newAddr)
{
  if (newAddr < 0 || newAddr > MAX_MODULE_ADDR) return;
  moduleAddress = newAddr;
}

int BMSModule::getAddress()
{
  return moduleAddress;
}

bool BMSModule::isExisting()
{
  return exists;
}

void BMSModule::settempsensor(int tempsensor)
{
  sensor = tempsensor;
}

void BMSModule::setExists(bool ex)
{
  exists = ex;
}

void BMSModule::setIgnoreCell(float Ignore)
{
  IgnoreCell = Ignore;
  Serial.print(Ignore);
  Serial.println();
}
