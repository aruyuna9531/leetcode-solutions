/*
	解数独
*/

#include<cstdio>
#include<stack>

bool legalInput(int arr[][9], int in_x, int in_y, int in_val){
	//判断输入/填数的合法性
	if(in_x < 0 || in_x >= 9 || in_y < 0 || in_y >= 9 || in_val <= 0 || in_val > 9)return false;	//无效输入
	int i,j;
	for(i = 0;i < 9; i++)if(arr[i][in_y]==in_val)return false;	//同一列已经有该数
	for(i = 0;i < 9; i++)if(arr[in_x][i]==in_val)return false;	//同一行
	int box_id = in_x/3*3+in_y/3;
	for(i = box_id/3*3; i < box_id/3*3+3; i++){
		for(j = box_id%3*3; j < box_id%3*3+3; j++){
			if(arr[i][j]==in_val)return false;						//同一个3*3内
		}
	}
	return true;
}

void print(int arr[][9]){
	//输出结果
	for(int i = 0;i < 9; i++){
		for(int j = 0; j < 9; j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int arr[9][9]={0};			//表格
	FILE *inputFile = fopen("D:/SudokuInput.txt", "r");
	//FILE *inputFile = NULL;		//手动输入数据时inputFile置为NULL
	int in_x, in_y, in_val;
	int filledNums = 0;
	while(fscanf(inputFile==NULL?stdin:inputFile, "%d%d%d", &in_x, &in_y, &in_val)!=EOF){
		if(!legalInput(arr, in_x-1, in_y-1, in_val))continue;
		arr[in_x-1][in_y-1]=in_val;
		filledNums++;
	}
	
	//开始求解
	int scan_place = 0, last_checkpoint = 1;
	bool no_solution=false;
	std::stack<int> scanRoad;		//记录回溯路径
	while(filledNums<81){			//已填81个数后结束（已经得出解）
		if(arr[scan_place/9][scan_place%9]!=0){
			//已经有数字了
			scan_place++;
			continue;
		}
		bool filled = false;		//标记这个格子是不是填了数
		for(int i = last_checkpoint;i <= 9;i++){
			//从回溯起点开始，找到第一个合法数字填入
			if(legalInput(arr, scan_place/9, scan_place%9, i)){
				arr[scan_place/9][scan_place%9] = i;
				filled=true;
				break;
			}
		}
		if(filled){
			//成功填入一个数字，往前走
			scanRoad.push(scan_place++);
			filledNums++;
			last_checkpoint = 1;
		}
		else{
			//该格子无法填入任何数字，产生了错误答案，需要回溯
			if(scanRoad.size()==0){
				no_solution = true;				//已经回溯到第一格，数独无解
				break;
			}
			scan_place = scanRoad.top();		//回溯一格
			scanRoad.pop();
			last_checkpoint = arr[scan_place/9][scan_place%9]+1;	//将回溯起点置为该格已填数+1，继续查
			arr[scan_place/9][scan_place%9]=0;	//由于while循环开头和legalInput判定需要当前格为0执行，这里需要对该格重置
			filledNums--;						//重置后计数器-1（防止循环提早结束，数独会填不完）
		}
	}
	
	if(!no_solution){
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				printf("%d ",arr[i][j]);
			}
			printf("\n");
		}
	}
	else printf("此数独无解\n");
	return 0;
}

/*
测试数据：SudokuInput.txt内容
1 2 2
1 8 1
2 4 8
2 6 5
3 1 8
3 3 1
3 7 6
3 9 4
4 2 3
4 3 2
4 4 7
4 6 4
4 7 5
4 8 9
5 1 6
5 9 8
6 2 8
6 3 5
6 4 2
6 6 9
6 7 1
6 8 7
7 1 2
7 3 8
7 7 4
7 9 9
8 4 4
8 6 1
9 2 9
9 8 5
*/
