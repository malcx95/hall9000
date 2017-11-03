import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
import { MainComponent } from './Pages/main.component'
import { AppComponent } from './app.component';
import { RouterModule, Routes } from '@angular/router'

const appRoutes: Routes = [
   { path: 'Main', component: MainComponent },
];

@NgModule({
  declarations: [
    AppComponent, MainComponent,
  ],
  imports: [
    BrowserModule, RouterModule.forRoot(appRoutes)
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule {}
