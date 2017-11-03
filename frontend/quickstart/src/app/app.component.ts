import { Component } from '@angular/core';
import { RouterModule } from '@angular/router';

@Component ({
   selector: 'app-root',
   template: '<a [routerLink] = "[\'Main\']"> Mein </a><router-outlet></router-outlet>'
})
export class AppComponent  {}
