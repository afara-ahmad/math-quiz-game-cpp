#include <iostream>
using namespace std;
enum enQuestionLevel { Easy = 1, Med = 2, Hard = 3, MixLevel = 4 };
enum enOperationType { Add = 1, Sub = 2, Div = 3, Mul = 4, MixOp = 5 };
int RandomNumber(int From,int To) {
	int Rand;
	Rand = rand() % (To - From + 1) + From;
	return Rand;
}
struct stQuestion {
	int Number1 = 0;
	int Number2 = 0;
	enQuestionLevel QuestionLevel;
	enOperationType OperationType;
	int CorrectAnswer = 0;
	int PlayerAnswer = 0;
	bool RigthAnswer = false;

};
struct stQuiz {
	stQuestion QuestionList[100];
	int QuestionNumber = 0;
	enQuestionLevel QuesLevel;
	enOperationType OpType;
	int NumberOfRightAnswers = 0;
	int NumberOfWrongAsnswers = 0;
	bool isPass = false;
};
int HowManyQuestion() {
	int NumberOfQuestion;
	do {
		cout << "How Many Question Do You Want To Answer ? ";
		cin >> NumberOfQuestion;

	} while (NumberOfQuestion < 1 || NumberOfQuestion>10);
	return NumberOfQuestion;
}
enQuestionLevel ReadQuestionLevel() {
	short Ques;
	do {
		cout << "Enter Question Level [1] Easy, [2] Med, [3] Hard, [4] Mix ?";
		cin >> Ques;
	} while (Ques < 1 || Ques>4);
	return (enQuestionLevel)Ques;
}
enOperationType ReadOpeartionType() {
	short Op;
	do {
		cout << "Enter Operation Type [1] Add, [2] Sub, [3] Div, [4] Mul, [5] Mix ?";
		cin >> Op;
	} while (Op < 1 || Op>5);
	return (enOperationType)Op;
}
void SetScreenColor(bool Right) {
	if (Right) {
		system("color 2F");

	}
	else
	{
		system("color 4F");
		cout << "\a";
	}
	


}
string GetSymbolOpType(enOperationType Op) {
	switch (Op) {
	case enOperationType::Add:
			return "+";
	case enOperationType::Sub:
		return "-";
	case enOperationType::Div:
		return "/";
	case  enOperationType::Mul:
		return "*";
	default:
		return "Mix";
	}
}
string GetQuestionLevelText(enQuestionLevel Question) {
	string arrQuestionLevel[4] = { "Easy","Med","Hard","Mix" };
	return arrQuestionLevel[Question - 1];
}
string GetFinalResultIsText(bool isPass) {
	if (isPass) {
		return "Pass :-)";

	}
	else {
		return "Fail :-( ";
	}
}
int SimpleCalculater(int Number1, int Number2, enOperationType Op) {
	switch (Op) {
	case enOperationType::Add:
		return Number1 + Number2;
	case enOperationType::Sub:
		return Number1 - Number2;
	case enOperationType::Div:
		return Number1 / Number2;
	case enOperationType::Mul:
		return Number1 * Number2;
	default:
		return Number1 + Number2;
	}
}
void PrintQuizzResults(stQuiz Quiz) {
	cout << "\n";
	cout << "________________________________\n\n";
	cout << "Final Result Is : " << GetFinalResultIsText(Quiz.isPass);
	cout << "\n________________________________\n\n";

	cout << "Number Of Question : " << Quiz.QuestionNumber << endl;
	cout << "Question Level : " << GetQuestionLevelText(Quiz.QuesLevel) << endl;
	cout << "Op Type : " << GetSymbolOpType(Quiz.OpType) << endl;
	cout << "Number Of Right Answers : " << Quiz.NumberOfRightAnswers << endl;
	cout << "Number Of Wrong Answers : " << Quiz.NumberOfWrongAsnswers << endl;
	cout << "___________________________________\n";
}
int ReadPlayerAnswer() {
	int Answer;
	cin >> Answer;
	return Answer;
}
void PrintQuestion(stQuiz& Quiz,int QuestionsNumber) {
	cout << "Question [ " << QuestionsNumber + 1 << "/" << Quiz.QuestionNumber << "] " << endl;
	cout << "\n";
	cout << Quiz.QuestionList[QuestionsNumber].Number1 << "\n";
	cout << Quiz.QuestionList[QuestionsNumber].Number2 << " " << GetSymbolOpType(Quiz.QuestionList[QuestionsNumber].OperationType) << endl;
	cout << "___________";
}
void CorrectTheQuestionAnswer(stQuiz &Quiz , short QuestionsNumber) {
	if (Quiz.QuestionList[QuestionsNumber].PlayerAnswer != Quiz.QuestionList[QuestionsNumber].CorrectAnswer) {
		Quiz.QuestionList[QuestionsNumber].RigthAnswer = false;
		Quiz.NumberOfWrongAsnswers++;

		cout << "Wrong Answer :-( \n";
		cout << "The Right Answer is : ";
		cout << Quiz.QuestionList[QuestionsNumber].CorrectAnswer;
		cout << "\n";
	}
	else {
		Quiz.QuestionList[QuestionsNumber].RigthAnswer = true;
		Quiz.NumberOfRightAnswers++;

		cout << "Right Answer :-) \n";

	}
	cout << endl;
	SetScreenColor(Quiz.QuestionList[QuestionsNumber].RigthAnswer);
}

void AskAndCorrectQuestionListAnswers(stQuiz &Quiz) {
	for (short QuestionsNumber = 0; QuestionsNumber < Quiz.QuestionNumber; QuestionsNumber++) {
		PrintQuestion(Quiz, QuestionsNumber);
		Quiz.QuestionList[QuestionsNumber].PlayerAnswer = ReadPlayerAnswer();
		CorrectTheQuestionAnswer(Quiz, QuestionsNumber);

   }
	if (Quiz.NumberOfRightAnswers >= Quiz.NumberOfWrongAsnswers) {
		Quiz.isPass = true;
	}
	else {
		Quiz.isPass = false;
	}
}
stQuestion GenerateQuestion(enOperationType Op ,enQuestionLevel Question) {
	stQuestion Ques;
	if (Question == enQuestionLevel::MixLevel) {
		Question = (enQuestionLevel)RandomNumber(1, 3);
	}
	if (Op == enOperationType::MixOp) {
		Op = (enOperationType)RandomNumber(1, 4);
	}
	Ques.OperationType = Op;
	switch (Question) {
	case enQuestionLevel::Easy:
		Ques.Number1 = RandomNumber(1, 10);
		Ques.Number2 = RandomNumber(1, 10);
		Ques.CorrectAnswer = SimpleCalculater(Ques.Number1, Ques.Number2, Ques.OperationType);
		Ques.QuestionLevel = Question;
		return Ques;

	case enQuestionLevel::Med:
		Ques.Number1 = RandomNumber(10, 50);
		Ques.Number2 = RandomNumber(10, 50);
		Ques.CorrectAnswer = SimpleCalculater(Ques.Number1, Ques.Number2, Ques.OperationType);
		Ques.QuestionLevel = Question;
		return Ques;

	case enQuestionLevel::Hard:
		Ques.Number1 = RandomNumber(50, 100);
		Ques.Number2 = RandomNumber(50, 100);
		Ques.CorrectAnswer = SimpleCalculater(Ques.Number1, Ques.Number2, Ques.OperationType);
		Ques.QuestionLevel = Question;
		return Ques;
	}
	return Ques;
}
void GenerateQuizQuestions(stQuiz &Quiz) {
	for (short NumberQuestion = 0; NumberQuestion < Quiz.QuestionNumber; NumberQuestion++) {
		Quiz.QuestionList[NumberQuestion] = GenerateQuestion(Quiz.OpType, Quiz.QuesLevel);
	}

}
void PlayMathGame() {
	stQuiz Quiz;
	Quiz.QuestionNumber = HowManyQuestion();
	Quiz.QuesLevel = ReadQuestionLevel();
	Quiz.OpType = ReadOpeartionType();

	GenerateQuizQuestions(Quiz);
	AskAndCorrectQuestionListAnswers(Quiz);
	PrintQuizzResults(Quiz);

}
void ResetScreen() {
	system("cls");
	system("color 07");
}
void StartGame() {
	char PlayAgain = 'Y';
	do {
		ResetScreen();
		PlayMathGame();
		cout << "\n";
		cout << "Do You Want To Play Again ? Y/N ? ";
		cin >> PlayAgain;
	} while (PlayAgain == 'Y' || PlayAgain == 'y');

}
int main() {
	srand((unsigned)time(NULL));
	StartGame();

}
	
		