class Solution:
    def findDuplicate(self, paths):
        content_map = defaultdict(list)

        for path in paths:
            parts = path.split(" ")
            directory = parts[0]

            for file_info in parts[1:]:
                file_name, content = file_info.split("(")
                content = content[:-1]  # remove ')'
                full_path = directory + "/" + file_name
                content_map[content].append(full_path)

        return [group for group in content_map.values() if len(group) > 1]