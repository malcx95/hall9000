from flask import Flask
from flask_login import LoginManager
from config import Config
from flask_sqlalchemy import SQLAlchemy
from flask_migrate import Migrate
from flask_basicauth import BasicAuth



from flask_admin import Admin



app = Flask(__name__)
app.config['DEBUG'] = True
app.config.from_object(Config)
db = SQLAlchemy(app)
migrate = Migrate(app, db)
login = LoginManager(app)

app.config['BASIC_AUTH_USERNAME'] ='kalle'
app.config['BASIC_AUTH_PASSWORD'] ='kalle'
login.login_view = 'login'
basic_auth = BasicAuth(app)

from server.views_models import ModelView
admin = Admin(app, name='run', template_mode='bootstrap3')
from server.models import User, Post, Cform, Book
admin.add_view(ModelView(User, db.session))
admin.add_view(ModelView(Post, db.session))
admin.add_view(ModelView(Book, db.session))
admin.add_view(ModelView(Cform, db.session))



from server import views, models
