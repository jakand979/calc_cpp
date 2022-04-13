#include <iostream>
#include <cmath>

class clubStats{
private:
    int goalsConceded;
    int goalsScored;
    int matchesPlayedThisWeek;
public:
    clubStats(int initConceded,int initScored,int initMatchesAmount);
    int getGoalsConceded() const;
    int getGoalsScored() const;
    int getAmountOfMatchesPlayed() const;
};

class playerStats{
private:
    int goalsScored;
    int assists;
    int matchesPlayedWeekly;
    int matchesPlayed;
public:
    playerStats(int goal,int assist,int weekly, int allMatches);
    int getGoals() const;
    int getAssist() const;
    int getWeekly() const;
    int getAllMatches() const;
};

playerStats::playerStats(int goal, int assist, int weekly, int allMatches) {
    goalsScored = goal;
    assists = assist;
    matchesPlayedWeekly = weekly;
    matchesPlayed = allMatches;
}

int playerStats::getGoals() const{
    return this->goalsScored;
}

int playerStats::getAssist() const {
    return this->assists;
}

int playerStats::getWeekly() const {
    return this->matchesPlayedWeekly;
}

int playerStats::getAllMatches() const {
    return this->matchesPlayed;
}

class cardOverall{
private:
    int OBR;
    int KON;
    int STR;
    int WPL;
    int POD;
    int REP;
public:
    cardOverall();
    int getOBR() const;
    void setOBR(int rateOBR);
    int getKON() const;
    void setKON(int rateKON);
    int getSTR() const;
    void setSTR(int rateSTR);
    int getWPL() const;
    void setWPL(int rateWPL);
    int getPOD() const;
    void setPOD(int ratePOD);
    int getREP() const;
    void setREP(int rateREP);
    void calculateOBR(clubStats exampleClub);
    void calculateKON();
    void calculateSTR(clubStats exampleClub, playerStats examplePlayer);
    void calculateWPL();
    void calculatePOD(clubStats exampleClub, playerStats examplePlayer);
    void calculateREP();
    void calculateALL();
    void printOverall() const;

};


cardOverall::cardOverall() {
    OBR = 0;
    KON = 0;
    STR = 0;
    WPL = 0;
    POD = 0;
    REP = 0;
}

int cardOverall::getOBR() const{
    return this->OBR;
}

void cardOverall::setOBR(int rateOBR){
    this->OBR = rateOBR;
}

int cardOverall::getKON() const{
    return this->KON;
}

void cardOverall::setKON(int rateKON){
    this->KON = rateKON;
}

int cardOverall::getSTR() const{
    return this->STR;
}

void cardOverall::setSTR(int rateSTR){
    this->STR = rateSTR;
}

int cardOverall::getWPL() const{
    return this->WPL;
}

void cardOverall::setWPL(int rateWPL){
    this->WPL = rateWPL;
}

int cardOverall::getPOD() const{
    return this->POD;
}

void cardOverall::setPOD(int ratePOD){
    this->POD = ratePOD;
}

int cardOverall::getREP() const{
    return this->REP;
}

void cardOverall::setREP(int rateREP){
    this->REP = rateREP;
}

void cardOverall::calculatePOD(clubStats exampleClubStats, playerStats examplePlayerStats){
    int scoredGoals = exampleClubStats.getGoalsScored();
    int assists = examplePlayerStats.getAssist();
    double assist = (double)assists/(double)scoredGoals;
    double podRatio = assist * 100.0;
    std::cout << podRatio << std::endl;
}

void cardOverall::calculateOBR(clubStats exampleClubStats){
    int lostGoals = exampleClubStats.getGoalsConceded();
    int matches = exampleClubStats.getAmountOfMatchesPlayed();
    double losingGoalsRatio = (double)lostGoals/(double)matches;
    double modulo = fmod(losingGoalsRatio,1.0);
    if(losingGoalsRatio <= 1){
        int range = 9;
        double addition = round((double)range * modulo);
        setOBR(99-(int)addition);
    }
    else if(losingGoalsRatio> 1 && losingGoalsRatio <= 3){
        int range = 9;
        double addition = round((double)range * modulo);
        setOBR(89-(int)addition);
    }
    else if(losingGoalsRatio > 3 && losingGoalsRatio <= 4){
        int range = 9;
        double addition = round((double)range * modulo);
        setOBR(79-(int)addition);
    }
    else if(losingGoalsRatio > 4 && losingGoalsRatio <= 5){
        int range = 9;
        double addition = round((double)range * modulo);
        setOBR(69-(int)addition);
    }
    else if(losingGoalsRatio > 5 && losingGoalsRatio <= 6){
        int range = 9;
        double addition = round((double)range * modulo);
        setOBR(59-(int)addition);
    }
    else if(losingGoalsRatio > 6 && losingGoalsRatio <= 7){
        int range = 9;
        double addition = round((double)range * modulo);
        setOBR(49-(int)addition);
    }
    else if(losingGoalsRatio > 7 && losingGoalsRatio <= 8){
        int range = 9;
        double addition = round((double)range * modulo);
        setOBR(39-(int)addition);
    }
    else{
        int range = 19;
        double addition = round((double)range * modulo);
        setOBR(29-(int)addition);
    }
}

void cardOverall::calculateSTR(clubStats exampleClub, playerStats examplePlayer) {
    int playerGoals = examplePlayer.getGoals();
    int teamGoals = exampleClub.getGoalsScored();
    double strikerRatio = ((double)playerGoals/(double)teamGoals)*100.0;
    double modulo = fmod(strikerRatio,1.0);
    if(strikerRatio >= 0 && strikerRatio <= 10 ){
        int range = 9;
        double addition = round((double)range * modulo);
        setSTR(50+(int)addition);
    }
    else if(strikerRatio > 10 && strikerRatio < 11){
        setSTR(59);
    }
    else if(strikerRatio >= 11 && strikerRatio <= 30){
        int range = 9;
        double addition = round((double)range * modulo);
        setSTR(60+(int)addition);
    }
    else if(strikerRatio > 30 && strikerRatio < 31){
        setSTR(69);
    }
    else if(strikerRatio >= 31 && strikerRatio <= 50){
        int range = 5;
        double addition = round((double)range * modulo);
        setSTR(70+(int)addition);
    }
    else if(strikerRatio > 50 && strikerRatio < 51){
        setSTR(75);
    }
    else if(strikerRatio >= 51 && strikerRatio <= 70){
        int range = 4;
        double addition = round((double)range * modulo);
        setSTR(76+(int)addition);
    }
    else if(strikerRatio > 70 && strikerRatio < 71){
        setSTR(80);
    }
    else{
        int range = 18;
        double addition = round((double)range * modulo);
        setSTR(81+(int)addition);
    }


}

void cardOverall::printOverall() const{
    std::cout << "STR " << getSTR() << " KON " << getKON() << std::endl;
    std::cout << "POD " << getPOD() << " OBR " << getOBR() << std::endl;
    std::cout << "WPL " << getWPL() << " REP " << getREP();
}

clubStats::clubStats(int initConceded,int initScored,int initMatchesAmount){
    goalsConceded = initConceded;
    goalsScored = initScored;
    matchesPlayedThisWeek = initMatchesAmount;
}

int clubStats::getGoalsConceded() const {
    return this->goalsConceded;
}

int clubStats::getGoalsScored() const {
    return this->goalsScored;
}

int clubStats::getAmountOfMatchesPlayed() const {
    return this->matchesPlayedThisWeek;
}

int main() {
    clubStats exampleClubStats(15,30,3);
    playerStats examplePlayer(6,10,11,12);
    cardOverall exampleCard;
    exampleCard.calculateOBR(exampleClubStats);
    exampleCard.calculatePOD(exampleClubStats,examplePlayer);
    exampleCard.printOverall();
    return 0;
}