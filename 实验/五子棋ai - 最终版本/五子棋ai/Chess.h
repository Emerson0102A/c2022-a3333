#pragma once
#include<graphics.h>
#include<vector>
using namespace std;

#define CHESSMAP_WIDTH 800
#define CHESSMAP_HEIGHT 595
#define PICTURE_WIDTH 595
#define PICTURE_HEIGHT 595
#define background COLORREF RGB(222,192,164)
typedef struct ChessPos
{
	int x;
	int y;
	ChessPos(int r = 0, int c = 0) :x(r), y(c) {}
}chesspos;

typedef enum
{
	CHESS_WHITE = -1,
	CHESS_BLACK = 1
}chess_kind_t;


class Chess
{
public:
	Chess(int gradeSize, int marginX, int marginY, float chessSize);

	//存储当前棋局棋子分布数据
	vector<vector<int>> chessmap;
	
	void init();//初始化棋盘
	
	bool clickBoard(int x, int y, ChessPos* pos);//检查落点是否有效
	
	void chessDown(ChessPos* pos, chess_kind_t kind);//棋子落点位置，表示落子

	int getGradeSize();//此函数获取棋盘大小o

	//获取指定位置是黑棋还是白棋还是空白
	
	int getChessData(int row, int col);
	int getChessData(ChessPos *pos);
	
	bool checkOver();//检查棋局是否结束
	bool checkwin();//判断胜负
	bool changchessif=false;//换子的判定值
	bool changEchessif;//换子的判定值,是否换子
	int gobacktimes;
	void changechess();//换子
	void gobackchess();//悔棋
	void faill();//认输
	vector <chesspos> backlist;

private :
	IMAGE blackchessImg;//黑棋
	IMAGE whitechessImg;//白棋
	IMAGE smallmap;//补地形

	int gradesize;//棋盘大小(13,15,17,19)
	int margin_x;//棋盘左侧边界长度
	int margin_y;//棋盘上边界边界长度

	float chesssize;//棋子的大小

	

	//表示下棋方妻子颜色
	//0:空     1：黑子    -1：白子
	bool playerFlag;
	
	//更新棋盘数据
	void updategameMap(chesspos* pos);

	//上个点的位置，以便后面判断正负和悔棋
	chesspos lastpos;
};

