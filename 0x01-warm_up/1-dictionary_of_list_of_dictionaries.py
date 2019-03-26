#!/usr/bin/python3
"""
Python script that, using this REST API, for a given employee ID,
returns information about his/her TODO list progress
"""
if __name__ == "__main__":
    import requests
    import json

    url = 'https://jsonplaceholder.typicode.com/users'
    q = requests.get(url).json()
    employee = {item.get('id'): item.get('name') for item in q}

    url_todo = 'https://jsonplaceholder.typicode.com/todos?userId='
    data = {}
    for employee_id in employee.keys():
        todos = requests.get('{}{}'.format(url_todo, employee_id)).json()
        value = [{'username': employee.get(todo.get('userId')),
                  'task': todo.get('title'),
                  'completed': todo.get('completed')}
                 for todo in todos]
        data[employee_id] = value

    with open('todo_all_employees.json', 'w') as f:
        json.dump(data, f)
