#ifndef ___SKYMAX_H
#define ___SKYMAX_H

#include <thread>
#include <mutex>

using namespace std;

class cSkymax
{
  unsigned char buf[1024]; //internal work buffer
  char status[1024];
  char mode;
  std::mutex m;
  void SetMode(char newmode);
  bool CheckCRC(unsigned char *buff, int len);
  bool query(const char *cmd, int replysize);
  uint16_t cal_crc_half(uint8_t *pin, uint8_t len);

public:
  cSkymax();
  void poll();
  void runMultiThread()
  {
    std::thread t1(&cSkymax::poll, this);
    t1.detach();
  }
  string *GetStatus();
  string *GetMode();
};

#endif // ___SKYMAX_H
