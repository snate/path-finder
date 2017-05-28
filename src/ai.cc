/**
 * @file
 * @brief  Brief description of file.
 * @author <stefanomunari.sm@gmail.com>
 *
 * Detailed description of file.
 */
#include "ai.h"
#include <map>
#include <vector>
#include <list>
#include <string>

using std::map;
using std::vector;
using std::list;
using std::string;

namespace path_finder
{

	AI* AI::_instance = nullptr;
	GraphRegistry AI::_registry = GraphRegistry();
	string AI::_subject = "";
	//GraphObserver AI::_graph_observer = GraphObserver();
	PathFinderActivator<string> AI::_path_finder = PathFinderActivator<string>();

	AI* AI::Instance(){
		return AI::_instance;
	}

	AI* AI::Instance(vector<string> factory_data,
		map<string,vector<string>> data_map,
		const string& subject_file, const string& subject_dir)
	{
		if(_instance  ==  nullptr)
			AI::_instance = new AI(factory_data, data_map, subject_file, subject_dir);
		return AI::_instance;
	}

	AI::AI(vector<string>& factory_data, map<string, vector<string>>& data_map,
		const string& subject_file, const string& subject_dir)
	{
		AI::_subject = subject_file;
		AI::_registry.SetFactory(factory_data);
		AI::_registry.AddGraph("static"+subject_file, data_map);
		//AI::_graph_observer.Observe(subject_dir);
	}

	#ifdef DEBUG
	void AI::Print(void){
		string name = "static"+AI::_subject;
		AI::_registry.PrintGraph(AI::_registry.GetGraph(name));
	}
	#endif /*DEBUG*/
}