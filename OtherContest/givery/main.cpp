#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <regex>
using namespace std;

struct Record{
  string timestamp;
  string distance;

  // 時間を取得
  int getHour() {
    return stoi(timestamp.substr(0, 2)) % 24;
  }
  // 分を取得
  int getMinute() {
    return stoi(timestamp.substr(3, 2));
  }
  // 経過1/100秒数を取得
  int get10ms() {
    return stoi(timestamp.substr(0, 2)) * 3600000 + stoi(timestamp.substr(3, 2)) * 60000 + stoi(timestamp.substr(6, 2)) * 1000 + stoi(timestamp.substr(9, 3));
  }

  // 深夜帯
  bool isMidnight() {
    return getHour() < 6;
  }
  // ピークタイム
  bool isPeakTime() {
    return (getHour() >= 6 && getHour() < 9) || (getHour() == 9 && getMinute() < 30 ) || ( getHour() >= 20 && getHour() < 24 );
  }

  // 距離
  double getDistance() {
    return stod(distance);
  }

  // 低速走行
  bool isLowSpeed(Record prev) {
    return getDistance() * 36 <= get10ms() - prev.get10ms();
  }


  // 初乗りレコードのバリデーション
  bool isValidFirst(){
    // hh:mm:ss.fff形式であるか
    regex pattern("^\\d{2}:\\d{2}:\\d{2}\\.\\d{3}$");
    if(!regex_match(timestamp, pattern)){
      return false;
    }
    // 走行距離が0.0であるか
    if(distance != "0.0"){
      return false;
    }
    return true;
  }

  // Recoudのバリデーション
  bool isValid(Record prev){
    // hh:mm:ss.fff形式であるか
    regex pattern("^\\d{2}:\\d{2}:\\d{2}\\.\\d{3}$");
    if(!regex_match(timestamp, pattern)){
      return false;
    }
    // 前回からの経過時間が45秒以内であるか
    if(get10ms() - prev.get10ms() > 45000){
      return false;
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  string line;
  vector<Record> records;
  while(getline(cin, line)){
    if(line.empty()) break;
    istringstream iss(line);
    string timestamp;
    string distance;

    iss >> timestamp >> distance;
    records.push_back({timestamp, distance});

    if(records.size() == 1){
      if(!records[0].isValidFirst()) return 1;
    } else {
      if(!records[records.size() - 1].isValid(records[records.size() - 2])) return 1;
    }
  }

  if(records.size() < 2){
    return 1;
  }

  long double distanceMeter = 0;
  int lowSpeedTimeMeter10ms = 0;
  int feeMeter = 0;
  for (auto i = 0; i < records.size(); i++){
    if(i == 0){
      // 初乗りレコード
      if(records[i].isMidnight()){
        feeMeter = 600;
      } else if(records[i].isPeakTime()) {
        feeMeter = 520;
      } else {
        feeMeter = 400;
      }
    } else {
      // 走行レコード
      // 距離メーター
      distanceMeter += records[i].getDistance();
      // 低速走行メーター
      if(records[i].isLowSpeed(records[i - 1])){
        lowSpeedTimeMeter10ms += records[i].get10ms() - records[i - 1].get10ms();
      }
      // 料金メーター
      if(distanceMeter < 1000){
      } else if (distanceMeter >= 1000 && distanceMeter < 10550){
        int feeCount = static_cast<int>((distanceMeter - 1000) / 400);
        int prevfeeCount = static_cast<int>((distanceMeter - records[i-1].getDistance() - 1000) / 400);
        if(distanceMeter - records[i-1].getDistance() - 1000 < 0){
          prevfeeCount = -1;
        }
        if(feeCount > prevfeeCount){
          if(records[i].isMidnight())
            feeMeter += 60;
          else if(records[i].isPeakTime())
            feeMeter += 52;
          else
            feeMeter += 40;
        }
      } else if (distanceMeter >= 10550){
        int feeCount = static_cast<int>((distanceMeter - 10200) / 350);
        int prevfeeCount = static_cast<int>((distanceMeter - records[i-1].getDistance() - 10200) / 350);
        if(feeCount > prevfeeCount){
          if(records[i].isMidnight())
            feeMeter += 60;
          else if(records[i].isPeakTime())
            feeMeter += 52;
          else
            feeMeter += 40;
        }
      }

      // 低速走行メーター
      int lowCount = lowSpeedTimeMeter10ms / 4500;
      int prevLowCount = (lowSpeedTimeMeter10ms - (records[i].get10ms() - records[i - 1].get10ms())) / 4500;
      if(lowCount > prevLowCount){
        if(records[i].isMidnight())
          feeMeter += 60;
        else if(records[i].isPeakTime())
          feeMeter += 52;
        else
          feeMeter += 40;
      }
    }
  }

  if(distanceMeter < 0.1){
    return 1;
  }

  cout << feeMeter << endl;
  return 0;
}
