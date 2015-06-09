#ifndef PACK_H
#define PACK_H

#include "Packs.h"
#include <fstream>
#include <iostream>

using namespace std;

class Pack{
	public:
		packs idPack;

		Pack() {};

		Pack(packs idP) {
			idPack = idP;
		};

		string toString() {
			switch (idPack) {
				case STARTTRAVEL:
					return "STARTTRAVEL";
					break;
				case PLAYTRAVEL:
					return "PLAYTRAVEL";
					break;
				case STOPTRAVEL:
					return "STOPTRAVEL";
					break;
				case PLAYTILE:
					return "PLAYTILE";
					break;
				case PILEWHENTRAVEL:
					return "PILEWHENTRAVEL";
					break;
				case IWANTPLAY:
					return "IWANTPLAY";
					break;
				case STARTGAME:
					return "STARTGAME";
					break;
				case CREATEGAME:
					return "CREATEGAME";
					break;
				case DEBUG:
					return "DEBUG";
					break;
				case QUIT:
					return "QUIT";
					break;
				case INITGAME:
					return "INITGAME";
					break;
				case PLAYEDTILE:
					return "PLAYEDTILE";
					break;
				case PLAYEDTRAVEL:
					return "PLAYEDTRAVEL";
					break;
				case STARTEDTRAVEL:
					return "STARTEDTRAVEL";
					break;
				case STOPPEDTRAVEL:
					return "STOPPEDTRAVEL";
					break;
				case VALIDATION:
					return "VALIDATION";
					break;
				case WON:
					return "WON";
					break;
				case PILEPLAYER:
					return "PILEPLAYER";
					break;
				case NEWPLAYERADD:
					return "NEWPLAYERADD";
					break;
				case YOURIDPLAYER:
					return "YOURIDPLAYER";
					break;
				case GOAL:
					return "GOAL";
					break;
				case CIRCULARQUEUECLIENT:
					return "CIRCULARQUEUECLIENT";
					break;
				case IWANTPLAYNETWORK:
					return "IWANTPLAYNETWORK";
					break;
				case REFRESHGAMESNETWORK:
					return "REFRESHGAMESNETWORK";
					break;
				case RESPONSEREFRESH:
					return "RESPONSEREFRESH";
					break;
				case GAMECREATENETWORK:
					return "GAMECREATENETWORK";
					break;
				case REFRESHPLAYERGAME:
					return "REFRESHPLAYERGAME";
					break;
				case RESPONSEPLAYERREFRESH:
					return "RESPONSEPLAYERREFRESH";
					break;
				case CREATEGAMENETWORK:
					return "CREATEGAMENETWORK";
					break;
				default:
					return "undefined pack ";
				break;
			}
		}

		virtual ~Pack() {};

		friend std::ostream& operator << (std::ostream &f, Pack &t){
			t.print(f);
			return f;
		};
		friend std::istream& operator >> (std::istream &f, Pack &t){
			t.read(f);
			return f;
		};

		virtual void print(std::ostream& f){
			f << (int)idPack << " ";
		};
		virtual void read(std::istream& f){
			int i;
			f >> i;
			idPack = (packs)i;
		};
};

#endif
