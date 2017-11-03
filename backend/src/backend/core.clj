(ns backend.core
  (:require [ring.util.response :refer [file-response]]
            [ring.adapter.jetty :refer [run-jetty]]
            [compojure.core :refer [defroutes GET PUT]]
            [compojure.route :as route]
            [compojure.handler :as handler])
  (:gen-class))

(defn index []
  (file-response ""))

(defn handler [request]
  {:status 200
   :headers {"Content-Type" "text/html"}
   :body (str "Hello World" request)})

(defroutes app
  (GET "/" [] "<h1>Hello world</h1>")
  (GET "/user/:id" [id]
       (str "<h1>Hello user " id "</h1>"))
  (route/not-found "<h1>Page not found</h1>"))

(defn -main
  "I don't do a whole lot ... yet."
  [& args]
  (println "Hello, World!"))
