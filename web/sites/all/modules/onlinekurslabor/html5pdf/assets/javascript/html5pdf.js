

// Define a class like this
function HTML5PDF(options, jqueryelement)
{
    this.pdffile = options.pdffile,
      this.pdfDoc = null,
      //current page
      this.pageNum = 1,
      //is a page rendering atm?
      this.pageRendering = false,
      //if so which one
      this.pageNumPending = null,
      //how many pages in pdf?
      this.pageNumTotal = 1, //wird automatisch gesetzt
      //scale of pdf
      this.scale = 3;
      //calculated automatically so that the pdf fits in the given width (see below)
      this.defaultscale = 1.0;
      //given option width: how much width do we have to render the pdf?
      this.containerwidth = options.width.replace(/\D/g,'');;
      //id of an html-object in which the total number of the pdf is written
      this.html_pagecount_id = options.html_pagecount_id;
      //id of an html-object in which the current sitenumber is written
      this.html_currentpage_id = options.html_currentpage_id;
      //id of an html-canvas into which the pdf will be rendered in 
      this.canvas =  document.getElementById(options.html_pdfcanvas_id),
      //automatically
      this.canvascontext = this.canvas.getContext('2d');
      this.initizialized = false;
      
  
}

HTML5PDF.prototype.getPageCount = function()
{   if( this.pdfDoc)
    {
     this.pageNumTotal  = this.pdfDoc.numPages;
     return this.pageNumTotal ;
    }
 else return -1 ;
}

HTML5PDF.prototype.resetScale = function()
{
    this.scale = this.defaultscale;
}


/*public, go to pdf-page num of document*/
HTML5PDF.prototype.goToPage = function(num)
{   //  this.resetScale();
    //cast to num if its a string
    num = num - 0;
      this.setpageNum(num);
      this.queueRenderPage(this.getpageNum());
}
/* public, get on pdf-site up */
HTML5PDF.prototype.pageUp = function()
{   //  this.resetScale();
      this.setpageNum(this.getpageNum()+1);
      this.queueRenderPage(this.getpageNum());
}

/* public, get on pdf-site down */
HTML5PDF.prototype.pageDown = function()
{  // this.resetScale();
     this.setpageNum(this.getpageNum()-1);
      this.queueRenderPage(this.getpageNum());
}
/*gets current pdf-site, 1 = min, count(pages) = max*/
HTML5PDF.prototype.getpageNum = function()
{
    return this.pageNum;
}
/*internal function, sets a new pagenum and checks for validaty*/
HTML5PDF.prototype.setpageNum = function(pageNum)
{
    if(pageNum >= 1 && pageNum <= this.getPageCount())
      this.pageNum = pageNum;
}
/*set scale for the pdf-document*/
HTML5PDF.prototype.setScale = function(scale)
{
    this.scale = scale;
    this.renderPage(this.getpageNum());
}
/*get scale for document*/
HTML5PDF.prototype.getScale= function()
{
  return    this.scale ;
}
/*public zoom by 25%*/
HTML5PDF.prototype.zoomIn = function()
{ 
    this.setScale(this.getScale() * 1.25);
}
/*public decrease zoom by 25%*/
HTML5PDF.prototype.zoomOut = function()
{
    this.setScale(this.getScale() / 1.25);
}

/*public function, loads the library first and afterwards a pdf specified in settings*/
HTML5PDF.prototype.loadPDF = function(optionalcallback, errorcallback)
{
    var innerthis = this;
    
    var loadingTask = pdfjsLib.getDocument(this.pdffile);
 
    loadingTask.promise.then(function(pdfDoc_) {
        innerthis.pdfDoc = pdfDoc_;
        innerthis.initializePDF();
        //optionales callback nach Aufruf der renderPage
        optionalcallback() ;
    }, function(reason) {
      errorcallback(reason);
    });

}


/**
 * private: initialize the PDF-Document and set the default scale of the document
 */
HTML5PDF.prototype.initializePDF = function() {
    var innerthis = this;
    this.pdfDoc.getPage(1).then(function(page) {
        innerthis.initizialized = true;
        /*calculate canvas size and scale */
        var chkport = page.getViewport({scale: 1});
        innerthis.defaultscale = 0.95 * innerthis.containerwidth / chkport.width;
        innerthis.resetScale();
        //set counter of html-element
        document.getElementById(innerthis.html_pagecount_id).textContent =  innerthis.getPageCount();
        innerthis.queueRenderPage(1);
    });

}
   
 /**
  * 
   * private: Get page info from document, resize canvas accordingly, and render page.
   * @param num Page number min-range:1.
   */
HTML5PDF.prototype.renderPage = function(num) {
    if(!this.initizialized)
        return false;
    this.pageRendering = true;
    // Using promise to fetch the page

    var innerthis = this;
    this.pdfDoc.getPage(num).then(function(page) {
        //var viewport = page.getViewport(1.0);
        //  innerthis.defaultscale = innerthis.containerwidth  
        var viewport = page.getViewport({scale: innerthis.scale});
        
        // resizing canvas...
        innerthis.canvas.height = viewport.height;
        innerthis.canvas.width = viewport.width;

        // Render PDF page into canvas context
        var renderContext = {
            canvasContext: innerthis.canvascontext,
            viewport: viewport
        };
        var renderTask = page.render(renderContext);

        // Wait for rendering to finish
        //todo: implement for zoom as well
        renderTask.promise.then(function() {
            innerthis.pageRendering = false;
            if (innerthis.pageNumPending !== null) {
                // New page rendering is pending
                innerthis.renderPage(innerthis.pageNumPending);
                innerthis.pageNumPending = null;
            }
        });
    });

    // Update page counters
    document.getElementById(this.html_currentpage_id).textContent = this.getpageNum();
}
    /**
   * If another page rendering in progress, waits until the rendering is
   * finised. Otherwise, executes rendering immediately.
   */
HTML5PDF.prototype.queueRenderPage  = function(num) {
    if (this.pageRendering) {
      this.pageNumPending = num;
    } else {
      this.renderPage(num);
    }
  }
