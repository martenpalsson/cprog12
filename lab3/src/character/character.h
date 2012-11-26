#ifndef CHARACTER_H
#define CHARACTER_H
namespace game {
	
	#
	struct Character{
		string name;
		string type;

		string type();
		string name();
		string go(string direction);
		string drop(string object);
		string pick_up(string object);
		
		virtual string action() = 0;
		virtual string fight(string character) = 0;
		virtual string talk_to(string character) = 0;

	};
};
