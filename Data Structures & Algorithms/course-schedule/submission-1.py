class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:

        graph = [[] for _ in range(numCourses)]
        indegree = [0] * numCourses

        # Build graph and indegree array
        for p in prerequisites:
            course = p[0]
            prereq = p[1]

            graph[prereq].append(course)
            indegree[course] += 1

        q = collections.deque()

        # Push all courses with indegree 0
        for i in range(numCourses):
            if indegree[i] == 0:
                q.append(i)

        completed = 0

        while q:
            curr = q.popleft()

            completed += 1

            for next_course in graph[curr]:
                indegree[next_course] -= 1

                if indegree[next_course] == 0:
                    q.append(next_course)

        return completed == numCourses