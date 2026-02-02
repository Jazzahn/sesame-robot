#pragma once

#include <Arduino.h>

enum FaceAnimMode : uint8_t {
  FACE_ANIM_LOOP = 0,
  FACE_ANIM_ONCE = 1,
  FACE_ANIM_BOOMERANG = 2
};

// External globals and helpers used by movement/pose sequences
extern int frameDelay;
extern int walkCycles;
extern String currentCommand;
extern int servoTrim[8];

extern void setServoAngle(uint8_t channel, int angle);
extern void setFace(const String& faceName);
extern void setFaceMode(FaceAnimMode mode);
extern void setFaceWithMode(const String& faceName, FaceAnimMode mode);
extern void delayWithFace(unsigned long ms);
extern void enterIdle();
extern bool pressingCheck(String cmd, int ms);

// Pose/animation prototypes
void runRestPose();
void runStandPose(int face = 1);
void runWavePose();
void runDancePose();
void runSwimPose();
void runPointPose();
void runPushupPose();
void runBowPose();
void runCutePose();
void runFreakyPose();
void runWormPose();
void runShakePose();
void runShrugPose();
void runDeadPose();
void runCrabPose();
void runWalkPose();
void runWalkBackward();
void runTurnLeft();
void runTurnRight();

// ====== POSES ======
inline void runRestPose() { 
  Serial.println(F("REST")); 
  setFaceWithMode("rest", FACE_ANIM_BOOMERANG); 
  for (int i = 0; i < 8; i++) setServoAngle(i, 90 + servoTrim[i]); 
}

inline void runStandPose(int face) { 
  Serial.println(F("STAND")); 
  if (face == 1) setFaceWithMode("stand", FACE_ANIM_ONCE); 
  setServoAngle(0, 135 + servoTrim[0]); 
  setServoAngle(1, 45 + servoTrim[1]); 
  setServoAngle(2, 45 + servoTrim[2]); 
  setServoAngle(3, 135 + servoTrim[3]); 
  setServoAngle(4, 0 + servoTrim[4]); 
  setServoAngle(5, 180 + servoTrim[5]); 
  setServoAngle(6, 0 + servoTrim[6]); 
  setServoAngle(7, 180 + servoTrim[7]); 
  if (face == 1) enterIdle();
}

inline void runWavePose() { 
  Serial.println(F("WAVE")); 
  setFaceWithMode("wave", FACE_ANIM_ONCE); 
  runStandPose(0); 
  delayWithFace(200);
  setServoAngle(4, 80 + servoTrim[4]); setServoAngle(6, 180 + servoTrim[6]); 
  setServoAngle(3, 60 + servoTrim[3]); setServoAngle(0, 100 + servoTrim[0]); 
  delayWithFace(200);
  setServoAngle(6, 180 + servoTrim[6]); 
  delayWithFace(300); 
  for (int i = 0; i < 4; i++) { 
    setServoAngle(6, 180 + servoTrim[6]); delayWithFace(300); 
    setServoAngle(6, 100 + servoTrim[6]); delayWithFace(300); 
  } 
  runStandPose(1); 
  if (currentCommand == "wave") currentCommand = "";
}

inline void runDancePose() { 
  Serial.println(F("DANCE")); 
  setFaceWithMode("dance", FACE_ANIM_LOOP); 
  setServoAngle(0, 90 + servoTrim[0]); setServoAngle(1, 90 + servoTrim[1]); 
  setServoAngle(2, 90 + servoTrim[2]); setServoAngle(3, 90 + servoTrim[3]); 
  setServoAngle(4, 160 + servoTrim[4]); setServoAngle(5, 160 + servoTrim[5]); 
  setServoAngle(6, 10 + servoTrim[6]); setServoAngle(7, 10 + servoTrim[7]); 
  delayWithFace(300); 
  for (int i = 0; i < 5; i++) { 
    setServoAngle(4, 115 + servoTrim[4]); setServoAngle(5, 115 + servoTrim[5]); 
    setServoAngle(6, 10 + servoTrim[6]); setServoAngle(7, 10 + servoTrim[7]); 
    delayWithFace(300); 
    setServoAngle(4, 160 + servoTrim[4]); setServoAngle(5, 160 + servoTrim[5]); 
    setServoAngle(6, 65 + servoTrim[6]); setServoAngle(7, 65 + servoTrim[7]); 
    delayWithFace(300); 
  } 
  runStandPose(1); 
  if (currentCommand == "dance") currentCommand = "";
}

inline void runSwimPose() { 
  Serial.println(F("SWIM")); 
  setFaceWithMode("swim", FACE_ANIM_ONCE); 
  for (int i = 0; i < 8; i++) setServoAngle(i, 90 + servoTrim[i]); 
  for (int i = 0; i < 4; i++) { 
    setServoAngle(0, 135 + servoTrim[0]); setServoAngle(1, 45 + servoTrim[1]); 
    setServoAngle(2, 45 + servoTrim[2]); setServoAngle(3, 135 + servoTrim[3]); 
    delayWithFace(400); 
    setServoAngle(0, 90 + servoTrim[0]); setServoAngle(1, 90 + servoTrim[1]); 
    setServoAngle(2, 90 + servoTrim[2]); setServoAngle(3, 90 + servoTrim[3]); 
    delayWithFace(400); 
  } 
  runStandPose(1); 
  if (currentCommand == "swim") currentCommand = "";
}

inline void runPointPose() { 
  Serial.println(F("POINT")); 
  setFaceWithMode("point", FACE_ANIM_BOOMERANG); 
  setServoAngle(3, 60 + servoTrim[3]); setServoAngle(0, 135 + servoTrim[0]); 
  setServoAngle(1, 100 + servoTrim[1]); setServoAngle(7, 180 + servoTrim[7]); 
  setServoAngle(2, 25 + servoTrim[2]); setServoAngle(6, 145 + servoTrim[6]);
  setServoAngle(4, 80 + servoTrim[4]); setServoAngle(5, 170 + servoTrim[5]); 
  delayWithFace(2000); 
  runStandPose(1); 
  if (currentCommand == "point") currentCommand = "";
}

inline void runPushupPose() {
  Serial.println(F("PUSHUP"));
  setFaceWithMode("pushup", FACE_ANIM_ONCE);
  runStandPose(0); 
  delayWithFace(200);
  setServoAngle(2, 0 + servoTrim[2]);
  setServoAngle(0, 180 + servoTrim[0]);
  setServoAngle(6, 90 + servoTrim[6]);
  setServoAngle(5, 90 + servoTrim[5]);
  delayWithFace(500);
  for (int i = 0; i < 4; i++) {
    setServoAngle(6, 0 + servoTrim[6]);
    setServoAngle(5, 180 + servoTrim[5]);
    delayWithFace(600);
    setServoAngle(6, 90 + servoTrim[6]);
    setServoAngle(5, 90 + servoTrim[5]);
    delayWithFace(500);
  }
  runStandPose(1);
  if (currentCommand == "pushup") currentCommand = "";
}

inline void runBowPose() {
  Serial.println(F("BOW"));
  setFaceWithMode("bow", FACE_ANIM_ONCE);
  runStandPose(0); 
  delayWithFace(200);
  setServoAngle(2, 0 + servoTrim[2]);
  setServoAngle(0, 180 + servoTrim[0]);
  setServoAngle(6, 0 + servoTrim[6]);
  setServoAngle(5, 180 + servoTrim[5]);
  setServoAngle(3, 180 + servoTrim[3]);
  setServoAngle(1, 0 + servoTrim[1]);
  setServoAngle(4, 0 + servoTrim[4]);
  setServoAngle(7, 180 + servoTrim[7]);
  delayWithFace(600);
  setServoAngle(6, 90 + servoTrim[6]);
  setServoAngle(5, 90 + servoTrim[5]);
  delayWithFace(3000);
  runStandPose(1);
  if (currentCommand == "bow") currentCommand = "";
}

inline void runCutePose() {
  Serial.println(F("CUTE"));
  setFaceWithMode("cute", FACE_ANIM_ONCE);
  runStandPose(0); 
  delayWithFace(200);
  setServoAngle(3, 160 + servoTrim[3]);
  setServoAngle(1, 20 + servoTrim[1]);
  setServoAngle(4, 180 + servoTrim[4]);
  setServoAngle(7, 0 + servoTrim[7]);

  setServoAngle(2, 0 + servoTrim[2]);
  setServoAngle(0, 180 + servoTrim[0]);
  setServoAngle(6, 180 + servoTrim[6]);
  setServoAngle(5, 0 + servoTrim[5]);
  delayWithFace(200);
  for (int i = 0; i < 5; i++) {
    setServoAngle(4, 180 + servoTrim[4]);
    setServoAngle(7, 45 + servoTrim[7]);
    delayWithFace(300);
    setServoAngle(4, 135 + servoTrim[4]);
    setServoAngle(7, 0 + servoTrim[7]);
    delayWithFace(300);
  }
  runStandPose(1);
  if (currentCommand == "cute") currentCommand = "";
}

inline void runFreakyPose() {
  Serial.println(F("FREAKY"));
  setFaceWithMode("freaky", FACE_ANIM_ONCE);
  runStandPose(0); 
  delayWithFace(200);
  setServoAngle(2, 0 + servoTrim[2]);
  setServoAngle(0, 180 + servoTrim[0]);
  setServoAngle(3, 180 + servoTrim[3]);
  setServoAngle(1, 0 + servoTrim[1]);
  setServoAngle(4, 90 + servoTrim[4]);
  setServoAngle(5, 0 + servoTrim[5]);
  delayWithFace(200);
  for (int i = 0; i < 3; i++) {
    setServoAngle(5, 25 + servoTrim[5]);
    delayWithFace(400);
    setServoAngle(5, 0 + servoTrim[5]);
    delayWithFace(400);
  }
  runStandPose(1);
  if (currentCommand == "freaky") currentCommand = "";
}

inline void runWormPose() {
  Serial.println(F("WORM"));
  setFaceWithMode("worm", FACE_ANIM_ONCE);
  runStandPose(0);
  delayWithFace(200);
  setServoAngle(0, 180 + servoTrim[0]); setServoAngle(1, 0 + servoTrim[1]); setServoAngle(2, 0 + servoTrim[2]); setServoAngle(3, 180 + servoTrim[3]);
  setServoAngle(4, 90 + servoTrim[4]); setServoAngle(5, 90 + servoTrim[5]); setServoAngle(6, 90 + servoTrim[6]); setServoAngle(7, 90 + servoTrim[7]);
  delayWithFace(200);
  for(int i=0; i<5; i++) {
    setServoAngle(5, 45 + servoTrim[5]); setServoAngle(6, 135 + servoTrim[6]); setServoAngle(4, 45 + servoTrim[4]); setServoAngle(7, 135 + servoTrim[7]);
    delayWithFace(300);
    setServoAngle(5, 135 + servoTrim[5]); setServoAngle(6, 45 + servoTrim[6]); setServoAngle(4, 135 + servoTrim[4]); setServoAngle(7, 45 + servoTrim[7]);
    delayWithFace(300);
  }
  runStandPose(1);
  if (currentCommand == "worm") currentCommand = "";
}

inline void runShakePose() {
  Serial.println(F("SHAKE"));
  setFaceWithMode("shake", FACE_ANIM_ONCE);
  runStandPose(0);
  delayWithFace(200);
  setServoAngle(0, 135 + servoTrim[0]); setServoAngle(2, 45 + servoTrim[2]); setServoAngle(6, 90 + servoTrim[6]); setServoAngle(5, 90 + servoTrim[5]);
  setServoAngle(3, 90 + servoTrim[3]); setServoAngle(1, 90 + servoTrim[1]);
  delayWithFace(200);
  for(int i=0; i<5; i++) {
    setServoAngle(4, 45 + servoTrim[4]); setServoAngle(7, 135 + servoTrim[7]);
    delayWithFace(300);
    setServoAngle(4, 0 + servoTrim[4]); setServoAngle(7, 180 + servoTrim[7]);
    delayWithFace(300);
  }
  runStandPose(1);
  if (currentCommand == "shake") currentCommand = "";
}

inline void runShrugPose() {
  Serial.println(F("SHRUG"));
  runStandPose(0);
  setFaceWithMode("dead", FACE_ANIM_ONCE);
  delayWithFace(200);
  setServoAngle(5, 90 + servoTrim[5]); setServoAngle(4, 90 + servoTrim[4]); setServoAngle(6, 90 + servoTrim[6]); setServoAngle(7, 90 + servoTrim[7]);
  delayWithFace(1000);
  setFaceWithMode("shrug", FACE_ANIM_ONCE);
  setServoAngle(5, 0 + servoTrim[5]); setServoAngle(4, 180 + servoTrim[4]); setServoAngle(6, 180 + servoTrim[6]); setServoAngle(7, 0 + servoTrim[7]);
  delayWithFace(1500);
  runStandPose(1);
  if (currentCommand == "shrug") currentCommand = "";
}

inline void runDeadPose() {
  Serial.println(F("DEAD"));
  runStandPose(0);
  setFaceWithMode("dead", FACE_ANIM_BOOMERANG);
  delayWithFace(200);
  setServoAngle(5, 90 + servoTrim[5]); setServoAngle(4, 90 + servoTrim[4]); setServoAngle(6, 90 + servoTrim[6]); setServoAngle(7, 90 + servoTrim[7]);
  if (currentCommand == "dead") currentCommand = "";
}

inline void runCrabPose() {
  Serial.println(F("CRAB"));
  setFaceWithMode("crab", FACE_ANIM_ONCE);
  runStandPose(0);
  delayWithFace(200);
  setServoAngle(0, 90 + servoTrim[0]); setServoAngle(1, 90 + servoTrim[1]); setServoAngle(2, 90 + servoTrim[2]); setServoAngle(3, 90 + servoTrim[3]);
  setServoAngle(4, 0 + servoTrim[4]); setServoAngle(5, 180 + servoTrim[5]); setServoAngle(6, 45 + servoTrim[6]); setServoAngle(7, 135 + servoTrim[7]);
  for(int i=0; i<5; i++) {
    setServoAngle(4, 45 + servoTrim[4]); setServoAngle(5, 135 + servoTrim[5]); setServoAngle(6, 0 + servoTrim[6]); setServoAngle(7, 180 + servoTrim[7]);
    delayWithFace(300);
    setServoAngle(4, 0 + servoTrim[4]); setServoAngle(5, 180 + servoTrim[5]); setServoAngle(6, 45 + servoTrim[6]); setServoAngle(7, 135 + servoTrim[7]);
    delayWithFace(300);
  }
  runStandPose(1);
  if (currentCommand == "crab") currentCommand = "";
}

// --- MOVEMENT ANIMATIONS ---
inline void runWalkPose() {
  Serial.println(F("WALK FWD"));
  setFaceWithMode("walk", FACE_ANIM_ONCE);
  // Initial Step
  setServoAngle(5, 135 + servoTrim[5]); setServoAngle(6, 45 + servoTrim[6]);
  setServoAngle(1, 100 + servoTrim[1]); setServoAngle(2, 25 + servoTrim[2]);
  if (!pressingCheck("forward", frameDelay)) return;
  
  for (int i = 0; i < walkCycles; i++) {
    setServoAngle(5, 135 + servoTrim[5]); setServoAngle(6, 0 + servoTrim[6]);
    if (!pressingCheck("forward", frameDelay)) return;
    setServoAngle(7, 135 + servoTrim[7]); setServoAngle(3, 90 + servoTrim[3]);
    setServoAngle(4, 0 + servoTrim[4]); setServoAngle(0, 180 + servoTrim[0]);
    if (!pressingCheck("forward", frameDelay)) return;    
    setServoAngle(1, 45 + servoTrim[1]); setServoAngle(2, 90 + servoTrim[2]);
    if (!pressingCheck("forward", frameDelay)) return;
    setServoAngle(4, 45 + servoTrim[4]); setServoAngle(7, 180 + servoTrim[7]);
    if (!pressingCheck("forward", frameDelay)) return;
    setServoAngle(5, 180 + servoTrim[5]); setServoAngle(6, 45 + servoTrim[6]);
    setServoAngle(1, 90 + servoTrim[1]); setServoAngle(2, 0 + servoTrim[2]);
    if (!pressingCheck("forward", frameDelay)) return;  
    setServoAngle(3, 135 + servoTrim[3]); setServoAngle(0, 90 + servoTrim[0]);
    if (!pressingCheck("forward", frameDelay)) return;
  }
  runStandPose(1);
}

// Logic reversed from Walk
inline void runWalkBackward() {
  Serial.println(F("WALK BACK"));
  setFaceWithMode("walk", FACE_ANIM_ONCE);
  if (!pressingCheck("backward", frameDelay)) return;
  
  for (int i = 0; i < walkCycles; i++) {
    setServoAngle(5, 135 + servoTrim[5]); setServoAngle(6, 0 + servoTrim[6]);
    if (!pressingCheck("backward", frameDelay)) return;
    setServoAngle(7, 135 + servoTrim[7]); setServoAngle(3, 135 + servoTrim[3]);
    setServoAngle(4, 0 + servoTrim[4]); setServoAngle(0, 90 + servoTrim[0]);
    if (!pressingCheck("backward", frameDelay)) return;    
    setServoAngle(1, 90 + servoTrim[1]); setServoAngle(2, 0 + servoTrim[2]);
    if (!pressingCheck("backward", frameDelay)) return;
    setServoAngle(4, 45 + servoTrim[4]); setServoAngle(7, 180 + servoTrim[7]);
    if (!pressingCheck("backward", frameDelay)) return;
    setServoAngle(5, 180 + servoTrim[5]); setServoAngle(6, 45 + servoTrim[6]);
    setServoAngle(1, 45 + servoTrim[1]); setServoAngle(2, 90 + servoTrim[2]);
    if (!pressingCheck("backward", frameDelay)) return;  
    setServoAngle(3, 90 + servoTrim[3]); setServoAngle(0, 180 + servoTrim[0]);
    if (!pressingCheck("backward", frameDelay)) return;
  }
  runStandPose(1);
}

// Simple turn logic
inline void runTurnLeft() {
  Serial.println(F("TURN LEFT"));
  setFaceWithMode("walk", FACE_ANIM_ONCE);
  for (int i = 0; i < walkCycles; i++) {
    //legset 1 (R1 L2)
    setServoAngle(5, 135 + servoTrim[5]); setServoAngle(7, 135 + servoTrim[7]); 
    if (!pressingCheck("left", frameDelay)) return;
    setServoAngle(0, 180 + servoTrim[0]); setServoAngle(3, 180 + servoTrim[3]); 
    if (!pressingCheck("left", frameDelay)) return;
    setServoAngle(5, 180 + servoTrim[5]); setServoAngle(7, 180 + servoTrim[7]); 
    if (!pressingCheck("left", frameDelay)) return;
    setServoAngle(0, 135 + servoTrim[0]); setServoAngle(3, 135 + servoTrim[3]);
    if (!pressingCheck("left", frameDelay)) return;
      //legset 2 (R2 L1)
    setServoAngle(4, 45 + servoTrim[4]); setServoAngle(6, 45 + servoTrim[6]); 
    if (!pressingCheck("left", frameDelay)) return;
    setServoAngle(1, 90 + servoTrim[1]); setServoAngle(2, 90 + servoTrim[2]); 
    if (!pressingCheck("left", frameDelay)) return;
    setServoAngle(4, 0 + servoTrim[4]); setServoAngle(6, 0 + servoTrim[6]); 
    if (!pressingCheck("left", frameDelay)) return;
    setServoAngle(1, 45 + servoTrim[1]); setServoAngle(2, 45 + servoTrim[2]);
    if (!pressingCheck("left", frameDelay)) return;  
  }
  runStandPose(1);
}

inline void runTurnRight() {
  Serial.println(F("TURN RIGHT"));
  setFaceWithMode("walk", FACE_ANIM_ONCE);
  for (int i = 0; i < walkCycles; i++) {
    //legset 2 (R2 L1)
    setServoAngle(4, 45 + servoTrim[4]); setServoAngle(6, 45 + servoTrim[6]); 
    if (!pressingCheck("right", frameDelay)) return;
    setServoAngle(1, 0 + servoTrim[1]); setServoAngle(2, 0 + servoTrim[2]); 
    if (!pressingCheck("right", frameDelay)) return;
    setServoAngle(4, 0 + servoTrim[4]); setServoAngle(6, 0 + servoTrim[6]); 
    if (!pressingCheck("right", frameDelay)) return;
    setServoAngle(1, 45 + servoTrim[1]); setServoAngle(2, 45 + servoTrim[2]);
    if (!pressingCheck("right", frameDelay)) return;  
    //legset 1 (R1 L2)
    setServoAngle(5, 135 + servoTrim[5]); setServoAngle(7, 135 + servoTrim[7]); 
    if (!pressingCheck("right", frameDelay)) return;
    setServoAngle(0, 90 + servoTrim[0]); setServoAngle(3, 90 + servoTrim[3]); 
    if (!pressingCheck("right", frameDelay)) return;
    setServoAngle(5, 180 + servoTrim[5]); setServoAngle(7, 180 + servoTrim[7]); 
    if (!pressingCheck("right", frameDelay)) return;
    setServoAngle(0, 135 + servoTrim[0]); setServoAngle(3, 135 + servoTrim[3]);
    if (!pressingCheck("right", frameDelay)) return;
  }
  runStandPose(1);
}
