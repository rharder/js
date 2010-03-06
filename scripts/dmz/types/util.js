
Object.defineProperty(
   exports,
   "Epsilon",
   {
      get: function () { return  0.000000001; },
      set: function () { throw new Error("Attempting to set constant value Epsilon."); }
   }
);


exports.isZero = function (value) {

   return Math.abs (value) < exports.Epsilon;
};


exports.isNotZero = function (value) {

   return Math.abs (value) >= exports.Epsilon;
};


exports.isUndefined = function (val) { var ud; return val === ud; };


exports.hasFunction = function (obj, name) {
 
   return typeof obj[name] === "function";
};


exports.createError = function (message) {

   return new Error (message);
}