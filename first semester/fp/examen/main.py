from UI.ui import UI
from repository.repository import Repository
from service.controller import Controller
from domain.question import Question
repo = Repository('master.txt', Question.read_line, Question.write_line)
controller = Controller(repo)
ui = UI(repo, controller)
ui.start()