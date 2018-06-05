#imports
#fuck the queen
from server import app, db
from server.models import User, Post, Book, Cform

@app.shell_context_processor
def make_shell_context():
    return {'db': db, 'User': User, 'Post': Post, 'Book':Book, 'Cform':Cform}
