(ns backend.core
  (:require [ring.util.response :refer [file-response]]
            [ring.adapter.jetty :refer [run-jetty]]
            [compojure.core :refer [defroutes GET PUT]]
            [compojure.route :as route]
            [compojure.handler :as handler])
  (:gen-class))

(def frontend-path "../frontend/quickstart/dist")

(defn index []
  (file-response "index.html" {:root frontend-path}))

;; (defn handler [request]
;;   {:status 200
;;    :headers {"Content-Type" "text/html"}
;;    :body (str "Hello World" request)})

(defroutes app
  (GET "/" [] (index))
  (GET "/user/:id" [id]
       (str "<h1>Hello user " id "</h1>"))
  (route/files "/" {:root frontend-path})
  ;; (route/files "/" {:root "../frontend/quickstart"})
  (route/not-found "<h1>Page not found</h1>"))

(defn start-server []
  (def server (run-jetty app {:port 8080 :join? false})))

(defn restart-server []
  (.stop server)
  (start-server))

(defn -main
  "Starts the web server"
  [& args]
  (run-jetty app {:port 8080}))
