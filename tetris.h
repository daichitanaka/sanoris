#include <iostream>
#include <string>

struct Field{
	int high = 20;
	int width = 10;
};

class GameMode{
	public:
		bool InitTetrisField();
		char ReadKeyBoardRealTime(void);
		int ReadGameScore(void);
		void SetNextBlock(void);
		void SetNowBlock(void);
		void ChangeNowBlockToNextBlock(void);
		bool JudgeBlockRotateClock(void);
		bool JudgeBlockRotateAntiClock(void);
		bool JudgeGameOver();
	private:
		int score;
		enum Block_t {I, O, S, Z, J, L, T};
		bool sqare[int][int];
		struct Field field;

};
