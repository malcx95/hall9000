import { Component } from '@angular/core';
import { Router }  from '@angular/router';

@Component ({
   selector: 'app-root',
   template: 'Main <a class = "button" (click) = "onBack()">Butt</a>',
})

export class MainComponent {
  constructor(private _router: Router){}

   onBack(): void {
      this._router.navigate(['/']);
   }
}
