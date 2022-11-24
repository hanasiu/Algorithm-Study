#pragma once
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

struct MatchResult {
	string winning_team, losing_team;
};

unordered_map<string, unordered_set<string>> BuildGraph(const vector<MatchResult>& matches) {
	unordered_map<string, unordered_set<string>> graph;
	for (const MatchResult& match : matches) {
		graph[match.winning_team].emplace(match.losing_team);
	}
	return graph;
}

bool IsReachableDfs(const unordered_map<string, unordered_set<string>>& graph,
	const string& curr, const string& dest,
	unordered_set<string>* visited_ptr) {
	unordered_set<string>& visited = *visited_ptr;
	if (curr == dest) {
		return true;
	}
	else if (visited.count(curr) || !graph.count(curr)) {
		return false;
	}
	visited.emplace(curr);
	const unordered_set<string>& team_list = graph.at(curr);
	return std::any_of(team_list.begin(), team_list.end(), [&](const string& team) {
		return IsReachableDfs(graph, team, dest, visited_ptr);
		});
}

bool CanTeamABeatTeamB(const vector<MatchResult>& matches,
	const string& team_a, const string& team_b) {
	return IsReachableDfs(BuildGraph(matches), team_a, team_b,
		make_unique<unordered_set<string>>().get());
}

int main()
{
	
	return 0;
}
